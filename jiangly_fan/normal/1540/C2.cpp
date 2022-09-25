#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
constexpr int maxn = 100 + 1;
constexpr int maxm = 100000;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int c[maxn], b[maxn], sb[maxn], ssb[maxn];
LL dp[maxn * maxn], sum[maxn * maxn];
LL ans[maxm * 2 + 1];
void add(LL& x, LL y){
    x += y;
    if (x >= mod) x -= mod;
}
void sub(LL& x, LL y){
    x -= y;
    if (x < 0) x += mod;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i += 1) cin >> c[i];
    for (int i = 1; i < n; i += 1) cin >> b[i];
    for (int i = 1; i < n; i += 1) sb[i + 1] = sb[i] + b[i];
    for (int i = 1; i < n; i += 1) ssb[i + 1] = ssb[i] + sb[i + 1];
    int sc = 0;
    for (int i = 1; i <= n; i += 1) sc += c[i];
    auto get = [&](int x) {
        for (int i = 0; i <= sc; i += 1) dp[i] = 0;
        dp[0] = 1;
        int L = 0, R = 0;
        bool ok = true;
        for (int i = 1; i <= n; i += 1) {
            int cL = max(L, i * x + ssb[i]), cR = R + c[i];
            if (cL > cR) {
                ok = 0;
                break;
            }
            sum[L] = dp[L];
            for (int j = L + 1; j <= cR; j += 1) {
                sum[j] = sum[j - 1];
                add(sum[j], dp[j]);
            }
            for (int j = cR; j >= cL; j -= 1) {
                dp[j] = sum[j];
                if (j - c[i] > L) sub(dp[j], sum[j - c[i] - 1]);
            }
            L = cL;
            R = cR;
        }
        if (ok) for (int j = L; j <= R; j += 1) add(ans[x + maxm], dp[j]);
    };
    int L = -10000, R = 100;
    get(L);
    get(R);
    function<void(int, int)> dfs = [&](int L, int R) {
        if (L + 1 >= R) return;
        if (ans[L + maxm] == ans[R + maxm]) {
            for (int i = L + 1; i < R; i += 1) ans[i + maxm] = ans[L + maxm];
            return;
        }
        int M = (L + R) >> 1;
        get(M);
        dfs(L, M);
        dfs(M, R);
    };
    dfs(L, R);
    int q;
    for (cin >> q; q; q -= 1) {
        int x;
        cin >> x;
        if (x < -10000) cout << ans[maxm - 10000] << "\n";
        else if(x > 100) cout << 0 << "\n";
        else cout << ans[maxm + x] << "\n";
    }
    return 0;
}