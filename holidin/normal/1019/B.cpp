#include <bits/stdc++.h>
using namespace std;

int i, j, l, r, n, a, b, x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cout << "? 1" << endl;
    cin >> a;
    cout <<  "? " << 1 + n / 2 << endl;
    cin >> b;
    if (a == b) {
        cout << "! 1" << endl;
        return 0;
    }
    bool flag = (a > b);
    int l = 1, r = n / 2 + 1;
    while (r - l > 1) {
        x = (l + r) / 2;
        cout << "? " << x << endl;
        cin >> a;
        cout << "? " << x + n / 2 << endl;
        cin >> b;
        if (a == b) {
            cout << "! " << x << endl;
            return 0;
        }
        if ((flag && a > b) || (!flag && a < b))
            l = x;
        else
            r = x;
    }
    cout << "? " << l << endl;
    cin >> a;
    cout << "? " << l + n / 2 << endl;
    cin >> b;
    if (a != b) {
        cout << "! -1" << endl;
        return 0;
    }
    cout << "! " << l << endl;
}