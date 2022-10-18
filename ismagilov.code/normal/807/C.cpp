#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd "\n"; return 0;
#define all(v) v.begin(), v.end()

using namespace std;

const int MAXN = 1e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int dd = 0; dd < t; dd++) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        int l = max(0ll, (y + q - 1) / q);
        if (p != 0){
            l = max(l, (x + p - 1) / p);
        }
        int r = INF;
        while(r - l > 1) {
            int k = (r + l) / 2;
            int tek = p * k - x;
            int tek1 = q * k - y;
            if (tek <= tek1) {
                r = k;
            } else {
                l = k;
            }
        }
        int tek = p * l - x;
        int tek1 = q * l - y;
        if (tek >= 0 && tek1 >= 0 && tek <= tek1) {
            r = l;
        }
        tek = p * r - x;
        tek1 = q * r - y;
        if (tek >= 0 && tek1 >= 0 && tek <= tek1) {
            cout << tek1 << endl;
        }
        else{
            cout << -1 << endl;
        }

    }
}