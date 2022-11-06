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

int n, m;
int ch[100001], A[100001], B[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<pii> V;
        for (int i = 1; i <= m; ++i) {
            cin >> A[i] >> B[i];
            V.emplace_back(A[i], i);
            V.emplace_back(B[i], -i);
            ch[i] = 0;
        }
        sort(V.rbegin(), V.rend());
        llong cnt = 0, sum = 0, ans = 0;
        for (pii i : V) {
            if (i.se < 0) {
                i.se *= -1;
                if (ch[i.se]) {
                    ans = max(ans, sum + (n - cnt) * i.fs);
                }
                else if (cnt < n) {
                    ans = max(ans, sum + A[i.se] + (n - cnt - 1) * i.fs);
                }
            }
            else {
                if (cnt < n) ch[i.se] = 1, ++cnt, sum += i.fs;
                if (cnt == n) ans = max(ans, sum);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}