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

char S[1005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> S + 1;
        n = strlen(S + 1);
        int cnt[2] = {};
        for (int i = 1; i <= n; ++i) ++cnt[S[i] - '0'];
        int lcnt[2] = {}, rcnt[2] = {};
        rcnt[0] = cnt[0];
        rcnt[1] = cnt[1];
        int ans = n;
        for (int i = 0; i <= n; ++i) {
            if (i) {
                ++lcnt[S[i] - '0'];
                --rcnt[S[i] - '0'];
            }
            ans = min(ans, lcnt[1] + rcnt[0]);
            ans = min(ans, lcnt[0] + rcnt[1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}