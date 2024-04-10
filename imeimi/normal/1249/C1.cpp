#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int q;
    cin >> q;
    while (q--) {
        llong n, t;
        cin >> n;
        t = n;
        vector<int> P;
        while (n) {
            P.push_back(n % 3);
            n /= 3;
        }
        P.push_back(0);
        int cnt2 = 0;
        for (int i : P) if (i == 2) ++cnt2;
        if (cnt2 == 0) printf("%lld\n", t);
        else {
            llong ans = 9e18;
            llong p = 1;
            for (int i = 0; i < (int)P.size(); ++i, p *= 3) {
                if (P[i] == 2) --cnt2;
                if (cnt2 > 0 || P[i]) continue;
                llong sum = p;
                llong pp = p * 3;
                for (int j = i + 1; j < (int)P.size(); ++j, pp *= 3) {
                    sum += pp * P[j];
                }
                ans = min(ans, sum);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}