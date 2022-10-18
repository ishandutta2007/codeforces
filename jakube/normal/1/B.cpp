#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    auto reg = regex("R(\\d+)C(\\d+)");
    while (n --> 0) {
        string s;
        cin >> s;
        smatch sm;
        if (regex_match(s, sm, reg)) {
            int r = stoi(sm[1]);
            int c = stoi(sm[2]);
            c--;
            int digits = 1;
            if (c >= 26) {
                c -= 26;
                digits++;
            }
            if (c >= 26*26) {
                c -= 26*26;
                digits++;
            }
            if (c >= 26*26*26) {
                c -= 26*26*26;
                digits++;
            }
            if (c >= 26*26*26*26) {
                c -= 26*26*26*26;
                digits++;
            }

            string res = "";
            for (int k = 0; k < digits; k++) {
                res = (char)('A' + (c % 26)) + res;
                c /= 26;
            }

            cout << res  << r << '\n';
        } else {
            string t = "";
            int num = 0;
            for (char c : s) {
                if ('A' <= c && c <= 'Z')
                    t += c;
                else
                    num = num * 10 + (c - '0');
            }

            int result = 0;
            int base = 26;
            for (int c = 0; c < t.size() - 1; c++) {
                result += base;
                base *= 26;
            }

            int other = 0;
            for (char c : t) {
                other = 26 * other + (c - 'A');
            }

            cout << "R" << num << "C" << (result + other + 1) << '\n';
        }
    }
}

/*
 * 0 - A
 * 1 - B
 * ...
 * 25 - Z
 * 26 - AA
 *
 *
 */