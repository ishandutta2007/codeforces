#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

vector<vector<int> > g;
vector<vector<int> > dp;

void upd(int& val, int x) {
    val = max(val, x);
}

void dfs(int v, int p) {
    dp[v][0] = -1;
    dp[v][1] = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        int nx[2] = {-1, -1};
        for (int i = 0; i < 2; ++i) {
            if (dp[v][i] == -1) {
                continue;
            }
            for (int j = 0; j < 2; ++j) {
                if (dp[to][j] == -1) {
                    continue;
                }
                if (j == 0) {
                    upd(nx[i], dp[v][i] + dp[to][j] + 1);
                }
                upd(nx[i ^ j], dp[v][i] + dp[to][j]);
            }
        }
        dp[v][0] = nx[0];
        dp[v][1] = nx[1];
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    g.resize(n);
    dp = vector<vector<int> >(n, vector<int>(2, -1));

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, 0);

    cout << dp[0][0] << "\n";

}