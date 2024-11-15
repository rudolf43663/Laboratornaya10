#include <iostream>
#include <string>

using namespace std;

string toRoman(int num) {
    if (num <= 0 || num > 3999) return "Ошибка: число вне диапазона.";

    string result = "";
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            result += symbols[i];
            num -= values[i];
        }
    }
    return result;
}

int toArabic(const string& roman) {
    int arabic = 0;
    int prev = 0;
    for (int i = roman.length() - 1; i >= 0; i--) {
        char c = roman[i];
        int current = 0;

        switch (c) {
            case 'M': current = 1000; break;
            case 'D': current = 500; break;
            case 'C': current = 100; break;
            case 'L': current = 50; break;
            case 'X': current = 10; break;
            case 'V': current = 5; break;
            case 'I': current = 1; break;
            default: return -1; 
        }

        if (current < prev) arabic -= current;
        else arabic += current;
        prev = current;
    }
    return arabic;
}

int main() {
    int choice;
    cout << "1.Арабские в римские\n2.Римские в арабские\n ";
    cin >> choice;

    if (choice == 1) {
        int num;
        cout << "Введите число:";
        cin >> num;
        cout << toRoman(num) << endl;
    } else if (choice == 2) {
        string roman;
        cout << "Введите число:";
        cin >> roman;
        int arabic = toArabic(roman);
        if (arabic == -1) cout << "Некорректное число" << endl;
        else cout << arabic << endl;
    } else {
        cout << "Неверный выбор" << endl;
    }
    return 0;
}