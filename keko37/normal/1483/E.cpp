#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const llint LIM = 1e14 + 1;

llint t;

bool pitaj (llint x) {
    cout << "? " << x << endl;
    string s; cin >> s;
    return s == "Lucky!";
}

llint solve (llint lo, llint hi, int flg) {
    if (hi == lo + 1) return lo;
    if (flg == 0) {
        llint y = (lo + lo + hi) / 3;
        if (pitaj(y)) {
            return solve(y, hi, 1);
        } else {
            pitaj(lo);
            return solve(lo, y, 0);
        }
    } else {
        llint y = (lo + hi) / 2;
        if (pitaj(y)) {
            return solve(y, hi, 1);
        } else {
            return solve(lo, y, 0);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        if (!pitaj(1)) {
            cout << "! 0" << endl;
            continue;
        }
        llint pot = 1;
        llint lo = 1, hi = LIM;
        for (int i = 1; i <= 45; i++) {
            pot *= 2;
            if (pitaj(pot)) {
                lo = pot;
            } else {
                hi = pot;
                pitaj(pot / 2);
                pitaj(pot / 2);
                break;
            }
        }
        if (hi == LIM) pitaj(pot);
        llint res = solve(lo, hi, 0);
        cout << "! " << res << endl;
    }
    return 0;
}