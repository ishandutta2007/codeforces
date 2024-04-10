#include <bits/stdc++.h>

using namespace std;

#define int long long

char f(char a, char b) {
    char x = 'a';
    while (true) {
        if (x != a && x != b) {
            return x;
        }
        x++;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a[0] == a[1]) {
        cout << "YES" << endl;
        char c = a[0];
        if (b[0] == b[1]) {
            for (int i = 0; i < n; i++) {
                cout << "abc";
            }
        }
        else {
            if (b[0] == c) {
                char c1;
                c1 = f(b[1], c);
                for (int i = 0; i < n; i++) {
                    cout << b[1] << c << c1;
                }
            }
            else if (b[1] == c) {
                char c1;
                c1 = f(b[0], c);
                for (int i = 0; i < n; i++) {
                    cout << c1 << c << b[0];
                }
            }
            else {
                for (int i = 0;  i < n; i++) {
                    cout << b[0] << c << b[1];
                }
            }
        }
        return 0;
    }
    swap(a, b);
    if (a[0] == a[1]) {
        cout << "YES" << endl;
        char c = a[0];
        if (b[0] == b[1]) {
            for (int i = 0; i < n; i++) {
                cout << "abc";
            }
        }
        else {
            if (b[0] == c) {
                char c1;
                c1 = f(b[1], c);
                for (int i = 0; i < n; i++) {
                    cout << b[1] << c << c1;
                }
            }
            else if (b[1] == c) {
                char c1;
                c1 = f(b[0], c);
                for (int i = 0; i < n; i++) {
                    cout << c1 << c << b[0];
                }
            }
            else {
                for (int i = 0;  i < n; i++) {
                    cout << b[0] << c << b[1];
                }
            }
        }
        return 0;
    }
    if (a == b) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << a[0] << f(a[0], a[1]) << a[1];
        }
        return 0;
    }
    if (a[0] == b[1] && a[1] == b[0]) {
        cout << "YES" << endl;
        for (int i  = 0; i <n; i++) {
            cout << a[0];
        }
        for (int i  = 0; i <n; i++) {
            cout << f(a[1], a[0]);
        }
        for (int i  = 0; i <n; i++) {
            cout << a[1];
        }
        return 0;
    }
    if (a[1] == b[1]) {
        cout << "YES" << endl;
        for (int i  = 0; i <n; i++) {
            cout << a[1];
        }
        for (int i  = 0; i <n; i++) {
            cout << a[0] << b[0];
        }
        return 0;
    }
    if (a[0] == b[0]) {
        cout << "YES" << endl;
        for (int i  = 0; i <n; i++) {
            cout << a[1] << b[1];
        }
        for (int i  = 0; i <n; i++) {
            cout << a[0];
        }
        return 0;
    }
    if (a[1] == b[0]) {
        swap(a, b);
    }
    cout << "YES" << endl;
    swap(a, b);
    for (int i = 0; i < n; i++) {
        cout << a[1] << a[0] << b[1];
    }
}