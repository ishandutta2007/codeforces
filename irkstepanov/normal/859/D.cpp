#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int n;
int k;

vector<vector<ld> > p;
vector<vector<ld> > prob;

void dfs(int v, int tl, int tr) {
    if (tr == tl + 1) {
        prob[v][tl] = p[tl][tr];
        prob[v][tr] = p[tr][tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    dfs(v * 2, tl, tm);
    dfs(v * 2 + 1, tm + 1, tr);
    for (int i = tl; i <= tm; ++i) {
        for (int j = tm + 1; j <= tr; ++j) {
            prob[v][i] += prob[v * 2][i] * prob[v * 2 + 1][j] * p[i][j];
            prob[v][j] += prob[v * 2][i] * prob[v * 2 + 1][j] * p[j][i];
        }
    }
}

vector<ld> dp;

void solve(int v, int tl, int tr) {
    if (tl + 1 == tr) {
        dp[v] = max(p[tl][tr], p[tr][tl]);
        return;
    }
    int tm = (tl + tr) >> 1;
    solve(v * 2, tl, tm);
    solve(v * 2 + 1, tm + 1, tr);
    for (int i = tl; i <= tr; ++i) {
        int curr = i + n;
        int depth = 1;
        ld sum = 0;
        while (curr != v) {
            int par = (curr >> 1);
            sum += prob[par][i] * ld(depth);
            depth *= 2;
            if (curr == 2 * par && 2 * par + 1 < n) {
                sum += dp[2 * par + 1];
            } else if (2 * par < n) {
                sum += dp[2 * par];
            }
            curr >>= 1;
        }
        dp[v] = max(dp[v], sum);
    }
}

int main() {

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> k;

    n = (1 << k);

    p = vector<vector<ld> >(n, vector<ld>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j];
            p[i][j] /= 100.0;
        }
    }

    prob = vector<vector<ld> >(n, vector<ld>(n));

    dfs(1, 0, n - 1);

    dp.resize(n);
    solve(1, 0, n - 1);
    cout << fixed;
    cout.precision(12);
    cout << dp[1] << "\n";

}