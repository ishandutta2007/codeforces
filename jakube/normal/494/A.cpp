#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    int open = 0;
    int closed = 0;
    int missing = 0;
    for (char c : s) {
        open += c == '(';
        closed += c == ')';
        missing += c == '#';
    }

    int todo = open - closed;
    if (todo < missing) {
        cout << -1 << endl;
        return 0;
    }

    int a = 0;
    int bal = 0;

    for (char c : s) {
        if (c == '(') bal++;
        if (c == ')') {
            bal--;
            if (bal < 0) {
                cout << -1 << endl;
                return 0;
            }
        }
        if (c == '#') {
            a++;
            if (a < missing)
                bal--;
            else
                bal-= todo-missing+1;

            if (bal < 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= missing; i++) {
        cout << (i < missing ? 1 : todo-missing + 1) << '\n';
    }

    return 0;
}