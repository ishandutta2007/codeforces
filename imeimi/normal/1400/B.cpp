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
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int p, f, cs, cw, s, w;
        cin >> p >> f >> cs >> cw >> s >> w;
        if (s > w) swap(cs, cw), swap(s, w);
        int ans = 0;
        for (int i = 0; i <= cs && i * s <= p; ++i) {
            int use_s1 = i;
            int use_w1 = min((p - use_s1 * s) / w, cw);
            int use_s2 = min(f / s, cs - use_s1);
            int use_w2 = min((f - use_s2 * s) / w, cw - use_w1);
            ans = max(ans, use_s1 + use_w1 + use_s2 + use_w2);
        }
        printf("%d\n", ans);
    }
    return 0;
}