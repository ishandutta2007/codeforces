#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

bool check3(int a, int b, bool p) {
    if (a == 75 && b <= 69 && b >= 0) {
        if (p) {
            return true;
        }
        cout << "25:" << min(b, 23) << " ";
        b = max(b - 23, 0);
        cout << "25:" << min(b, 23) << " ";
        b = max(b - 23, 0);
        cout << "25:" << b;
    }
    if (a > 75 && a - 52 <= b && b <= a - 6) {
        if (p) {
            return true;
        }
        cout << a - 50 << ":" << a - 52 << " ";
        b -= a - 52;
        cout << "25:" << min(b, 23) << " ";
        b = max(b - 23, 0);
        cout << "25:" << b;
    }
    return false;
}

bool check35(int a, int b, bool p) {
    if (a == 65 && b <= 59 && b >= 0) {
        if (p) {
            return true;
        }
        cout << "25:" << min(b, 23) << " ";
        b = max(b - 23, 0);
        cout << "25:" << min(b, 23) << " ";
        b = max(b - 23, 0);
        cout << "15:" << b;
    }
    if (a > 65 && a - 52 <= b && b <= a - 6) {
        if (p) {
            return true;
        }
        int c = a - 50;
	int d = a - 52;
	a -= c;
	b -= d;
        cout << "25:" << min(b, 23) << " ";
        b = max(b - 23, 0);
        cout << "25:" << min(b, 23) << " ";
        b = max(b - 23, 0);
        cout << c << ":" << d;
    }
    return false;
}

bool check2(int a, int b, bool p) {
    if (a == 50 && b <= 46 && b >= 0) {
        if (p) {
            return true;
        }
        cout << "25:" << min(b, 23) << " ";
        b = max(b - 23, 0);
        cout << "25:" << b;
    }
    if (a > 50 && a - 27 <= b && b <= a - 4) {
        if (p) {
            return true;
        }
        cout << a - 25 << ":" << a - 27 << " ";
        b -= a - 27;
        cout << "25:" << b;
    }
    return false;
}

bool check1(int a, int b, bool p) {
    if (a == 25 && b <= 23 && b >= 0) {
        if (p) {
            return true;
        }
        cout << "25:" << b;
    }
    if (a > 25 && b == a - 2) {
        if (p) {
            return true;
        }
        cout << a << ":" << a - 2;
    }
    return false;
}

void solve() {
    int a, b;
    cin >> a >> b;
    if (check3(a, b, true)) {
        cout << "3:0\n";
        check3(a, b, false);
        cout << endl;
        return;
    }
    for (int i = 0; i <= a; ++i) {
        if (check3(a - i, b - max(25, i + 2), true)) {
            cout << "3:1\n";
            cout << i << ":" << max(25, i + 2) << " ";
            a -= i;
            b -= max(25, i + 2);
            check3(a, b, false);
            cout << endl;
            return;
        }
    }
    for (int i = 0; i <= a - 65; ++i) {
        for (int j = 0; j <= min(23, max(0, i - 23)); ++j) {
            if (check35(a - i, b - max(50, 25 + i - j + 2), true)) {
                cout << "3:2\n";
                cout << j << ":25 ";
                i -= j;
                cout << i << ":" << max(25, i + 2) << " ";
                a -= i;
                b -= max(50, i + 27);
                check35(a, b, false);
                cout << endl;
                return;
            }
        }
    }
    for (int i = 0; i <= a - 50; ++i) {
        for (int j = 0; j <= min(46, max(0, i - 13)); ++j) {
            if (check2(a - i, b - max(65, 50 + i - j + 2), true)) {
                cout << "2:3\n";
                check2(a - i, b - max(65, 50 + i - j + 2), false);
                cout << " ";
                i -= j;
                cout << min(j, 23) << ":25 ";
                j -= min(j, 23);
                cout << min(j, 23) << ":25 ";
                j -= min(j, 23);
                cout << i << ":" << max(15, i + 2) << endl;
                return;
            }
        }
    }
    for (int i = 0; i <= a - 25; ++i) {
        for (int j = 0; j <= min(46, max(0, i - 23)); ++j) {
            if (check1(a - i, b - max(75, 50 + i - j + 2), true)) {
                cout << "1:3\n";
                check1(a - i, b - max(75, 50 + i - j + 2), false);
                cout << " ";
                i -= j;
                cout << min(j, 23) << ":25 ";
                j -= min(j, 23);
                cout << min(j, 23) << ":25 ";
                j -= min(j, 23);
                cout << i << ":" << max(25, i + 2) << endl;
                return;
            }
        }
    }
    int i = a;
    for (int j = 0; j <= min(46, max(0, i - 23)); ++j) {
        if (b == max(75, 50 + i - j + 2)) {
            cout << "0:3\n";
            cout << min(j, 23) << ":25 ";
            i -= j;
            j -= min(j, 23);
            cout << min(j, 23) << ":25 ";
            j -= min(j, 23);
            cout << i << ":" << max(25, i + 2) << endl;
            return;
        }
    }
    cout << "Impossible" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);

    int m;
    cin >> m;
    while (m--) {
        solve();
    }
}