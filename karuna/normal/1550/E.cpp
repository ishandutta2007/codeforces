#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 2e5 + 10, N = 17;
int n, k, Dp[1 << N]; string S;
vector<int> V[M], X[N];
queue<pint> Q;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> k >> S;
    int lo = 0, hi = n;
    while (lo < hi) {
        int m = lo + hi + 1 >> 1;
        for (int i = 0; i < k; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                if (S[j] != 'a' + i && S[j] != '?') s += 1;
                if (j >= m && S[j - m] != 'a' + i && S[j - m] != '?') s -= 1;
                if (j >= m - 1 && s == 0) V[j].push_back(i);
            }
        }
        for (int i = 0; i < k; i++) {
            X[i].push_back(0);
        }
        memset(Dp, 0, sizeof Dp); Dp[0] = 1;
        for (int i = 0; i < n; i++) {
            while (!Q.empty() && Q.front().va <= i - m) {
                auto [a, b] = Q.front(); Q.pop();
                for (int j = 0; j < k; j++) if (~b >> j & 1) {
                    X[j].push_back(b);
                }
            }
            for (int x : V[i]) {
                for (int k : X[x]){
                    if (Dp[k | (1 << x)]) continue;
                    Dp[k | (1 << x)] = 1;
                    Q.emplace(i, k | (1 << x));
                }
                X[x].clear();
            }
        }
        for (int i = 0; i < n; i++) V[i].clear();
        for (int i = 0; i < k; i++) X[i].clear();
        while (!Q.empty()) Q.pop();
        
        if (Dp[(1 << k) - 1]) lo = m;
        else hi = m - 1;
    }
    cout << lo;
}