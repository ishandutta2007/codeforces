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

int x;
bool pos[1 << 21];
int dp[1 << 21];
int solve(vector<int> A) {
    vector<int> X(1, 1);
    dp[1] = 0;
    for (int x : A) {
        vector<pii> nxt;
        for (int b : X) {
            ++dp[b];
            int nb = (b << x | 1) & ((1 << ::x + 1) - 1);
            if (!pos[nb]) continue;
            nxt.emplace_back(nb, dp[b] - 1);
        }
        for (auto [b, v] : nxt) {
            if (dp[b] > 1e8) X.push_back(b);
            dp[b] = min(dp[b], v);
        }
    }
    int ans = 1e9;
    for (int b : X) ans = min(ans, dp[b]), dp[b] = 1e9;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    memset(dp, 0x1f, sizeof(dp));
    string s;
    cin >> s >> x;
    for (int b = 0; b < (1 << x + 1); ++b) {
        pos[b] = 1;
        vector<int> A;
        for (int i = 0; i <= x; ++i) if ((b >> i) & 1) A.push_back(i);
        if (A.empty() || A.back() < x) continue;
        int n = A.size();
        pos[b] = 0;
        for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) {
            if (A[i] - A[j] < x && x % (A[i] - A[j]) == 0) {
                pos[b] = 1;
                break;
            }
        }
    }
    vector<int> A;
    int ans = 0;
    for (char c : s) {
        int v = c - '0';
        if (x == v) {
            ++ans;
            continue;
        }
        if (x % v == 0 || x < v) {
            ans += solve(A);
            A.clear();
        }
        else A.push_back(v);
    }
    ans += solve(A);
    printf("%d\n", ans);
    return 0;
}