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

int n;
char S[200001];
int dp[20][200001];

int solve() {
    cin >> n >> S;
    char c = 'a';
    for (int l = n; l > 1; l >>= 1, ++c);
    for (int i = 0; i < n; ++i) {
        dp[c - 'a'][i] = (S[i] != c);
    }
    --c;
    for (int l = 2; l <= n; l <<= 1, --c) {
        int k = c - 'a';
        for (int i = 0; i < n; i += l) {
            int lv = dp[k + 1][i], rv = dp[k + 1][i + l / 2];
            for (int j = 0; j < l; ++j) {
                if (S[i + j] != c) ++(j < l / 2 ? rv : lv);
            }
            dp[k][i] = min(lv, rv);
        }
    }
    return dp[0][0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}