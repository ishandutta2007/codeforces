#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
//using ll = long long;
using ld = long double;
using pii = pair<int, int>;





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        bool ans = false;
        for (int ur = 0; ur <= 1 && !ans; ++ur) {
            for (int dr = 0; dr <= 1 && !ans; ++dr) {
                for (int ul = 0; ul <= 1 && !ans; ++ul) {
                    for (int dl = 0; dl <= 1 && !ans; ++dl) {
                        int uu = u - ur - ul;
                        int rr = r - ur - dr;
                        int ll = l - ul - dl;
                        int dd = d - dr - dl;
                        bool cur = true;
                        cur &= (uu >= 0) && (uu <= n - 2);
                        cur &= (rr >= 0) && (rr <= n - 2);
                        cur &= (ll >= 0) && (ll <= n - 2);
                        cur &= (dd >= 0) && (dd <= n - 2);
                        ans |= cur;
                    }
                }
            }
        }
        cout << (ans ? "yes" : "no") << "\n";
    }



}