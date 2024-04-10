#include "bits/stdc++.h"

using namespace std;

int n;

void upd(int& x) {
    x = n - x + 1;
}

void solve() {
    int x, y, x2, y2, x3, y3;
    cin >> n >> x >> y >> x2 >> y2 >> x3 >> y3;
    int a, b;
    cin >> a >> b;
    {
        map<int, int> cnt; cnt[x]++, cnt[x2]++, cnt[x3]++;
        if ((*cnt.begin()).second == 1) {
            upd(x), upd(x2), upd(x3), upd(a);
        }
    }
    {
        map<int, int> cnt; cnt[y]++, cnt[y2]++, cnt[y3]++;
        if ((*cnt.begin()).second == 1) {
            upd(y), upd(y2), upd(y3), upd(b);
        }
    }
    int X = min(x, x2);
    int Y = min(y, y2);
    if (X == 1 && Y == 1) {
        if (a == 1 || b == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    //cout << y << " " << y2 << " " << y3 << " " << b << endl;
    if (a % 2 == X % 2) {
        cout << "YES\n";
        return;
    } else if (b % 2 == Y % 2) {
        cout << "YES\n";
        return;
    }
    if (b % 2 == Y % 2) {
        cout << "YES\n";
        return;
    } else if (a % 2 == X % 2) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}