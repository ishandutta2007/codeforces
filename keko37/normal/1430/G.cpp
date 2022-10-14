#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 18;
const int INF = 1000000000;

int n, m;
int cost[MAXN], sus[MAXN], bio[MAXN], sol[MAXN];
int dp[1 << MAXN][MAXN + 1][MAXN + 1];
vector <int> v;

void dfs (int x) {
    if (bio[x]) return;
    bio[x] = 1;
    for (int i = 0; i < n; i++) {
        if (sus[i] & (1 << x)) dfs(i);
    }
    v.push_back(x);
}

void calc () {
    for (int mask = 0; mask < (1 << n); mask++) dp[mask][n][0] = INF;
    dp[(1 << n) - 1][n][0] = 0;
    for (int val = n - 1; val >= 0; val--) {
        for (int mask = 0; mask < (1 << n); mask++) dp[mask][val][n] = dp[mask][val + 1][0];
        for (int pos = n - 1; pos >= 0; pos--) {
            for (int mask = 0; mask < (1 << n); mask++) {
                int res = dp[mask][val][pos + 1];
                if ((mask & (1 << v[pos])) == 0 && (sus[v[pos]] & mask) == sus[v[pos]]) {
                    res = min(res, dp[mask | (1 << v[pos])][val][pos + 1] + val * cost[v[pos]]);
                }
                dp[mask][val][pos] = res;
            }
        }
    }
}

void construct (int mask, int val, int pos) {
    if (val == n) return;
    if (pos == n) {
        construct(mask, val + 1, 0);
    } else if (dp[mask][val][pos] == dp[mask][val][pos + 1]) {
        construct(mask, val, pos + 1);
    } else {
        sol[v[pos]] = val;
        construct(mask | (1 << v[pos]), val, pos + 1);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        cost[x] += w; cost[y] -= w;
        sus[x] |= 1 << y;
    }
    for (int i = 0; i < n; i++) dfs(i);
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int val = 0; val < n; val++) {
            for (int pos = 0; pos < n; pos++) {
                dp[mask][val][pos] = -INF;
            }
        }
    }
    calc();
    construct(0, 0, 0);
    for (int i = 0; i < n; i++) cout << sol[i] << " ";
    return 0;
}