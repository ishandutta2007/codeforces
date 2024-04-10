#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, x, y;

int presjek (pi a, pi b) {
    int lo = max(a.first, b.first);
    int hi = min(a.second, b.second);
    if (lo > hi) return 0;
    return hi - lo + 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> x >> y;
        y++;
        llint sol = 0;
        for (int b = 2; b <= min((int)1e5, y); b++) {
            sol += min(x / b, b - 2);
        }
        if (1e5 < y) {
            int lo = 1e5 + 1, hi = y;
            for (int val = 1; val <= 1e4; val++) {
                sol += presjek({lo, hi}, {x / (val + 1) + 1, x / val}) * val;
            }
        }
        cout << sol << '\n';
    }
    return 0;
}