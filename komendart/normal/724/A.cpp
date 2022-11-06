#include <bits/stdc++.h>

using namespace std;

int f(string s) {
    if (s == "monday") return 0;
    if (s == "tuesday") return 1;
    if (s == "wednesday") return 2;
    if (s == "thursday") return 3;
    if (s == "friday") return 4;
    if (s == "saturday") return 5;
    if (s == "sunday") return 6;
}

int main() {
    string a, b;
    cin >> a >> b;
    int x = f(a);
    int y = f(b);
    for (auto i: {28, 30, 31}) {
        if ((x + i - y) % 7 == 0) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}