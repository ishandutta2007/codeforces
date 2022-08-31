#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int P = 1E9 + 7, N = 3400;
void inc(int &a, int b) {(a += b) >= P ? a -= P : 0;}
vector<int> transform(vector<int> n, int base) {
    if (n.back() == 0)
        n.pop_back();
    vector<int> m;
    while (!n.empty()) {
        int x = 0;
        LL d = 0;
        for (int i = (int)n.size() - 1; i >= 0; --i) {
            x = (10LL * x + n[i]) % base;
            d = 10LL * d + n[i];
            n[i] = d / base;
            d %= base;
        }
        m.push_back(x);
        while (!n.empty() && n.back() == 0)
            n.pop_back();
    }
    return m;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p, a;
    cin >> p >> a;
    string ns;
    cin >> ns;
    vector<int> n(ns.begin(), ns.end());
    for (int &i : n)
        i -= '0';
    reverse(n.begin(), n.end());
    n = transform(n, p);
    if (a > (int)n.size()) {
        cout << 0 << endl;
        return 0;
    }
    int dp[2][N][2][2] {};
    int cur = 0, pre = 1;
    dp[0][0][0][0] = 1;
    function<int(int, int, int)> calcne = [&](int x, int c, int nc) {
        if (c)
            return (int)((1LL * p * x - calcne(x, 0, nc)) % P + P) % P;
        return (int)(1LL * (x - nc) * (x + 1 - nc) / 2 % P);
    };
    function<int(int, int, int)> calce = [&](int x, int c, int nc) {
        if (c)
            return p - calce(x, 0, nc);
        return x - nc;
    };
    for (int i = (int)n.size() - 1; i >= 0; --i) {
        swap(cur, pre);
        memset(dp[cur], 0, sizeof(dp[cur]));
        for (int j = 0; j <= a; ++j) {
            for (int e = 0; e < 2; ++e) {
                for (int c = 0; c < 2; ++c) {
                    int val = dp[pre][j][e][c];
                    if (val == 0)
                        continue;
                    for (int nc = 0; nc < 2; ++nc) {
                        int nj = min(a, j + nc);
                        if (e == 1) {
                            inc(dp[cur][nj][1][nc], 1LL * val * calcne(p, c, nc) % P);
                        } else {
                            inc(dp[cur][nj][1][nc], 1LL * val * calcne(n[i], c, nc) % P);
                            inc(dp[cur][nj][0][nc], 1LL * val * calce(n[i] + 1, c, nc) % P);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int e = 0; e < 2; ++e)
        inc(ans, dp[cur][a][e][0]);
    cout << ans << endl;
    return 0;
}