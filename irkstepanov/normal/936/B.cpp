#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

vector<vector<int> > g;
vector<vector<bool> > dp;
vector<vector<int> > pr;

void dfs(int v, int t) {
    for (int to : g[v]) {
        if (dp[to][t ^ 1]) {
            continue;
        }
        dp[to][t ^ 1] = true;
        pr[to][t ^ 1] = v;
        dfs(to, t ^ 1);
    }
}

vector<int> color;
bool cycle = false;

void dfs2(int v) {
    color[v] = 1;
    for (int to : g[v]) {
        if (color[to] == 1) {
            cycle = true;
        } else if (color[to] == 0) {
            dfs2(to);
        }
    }
    color[v] = 2;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    g.resize(n);
    dp = vector<vector<bool> >(n, vector<bool>(2, false));
    pr = vector<vector<int> >(n, vector<int>(2, -1));

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int to;
            cin >> to;
            --to;
            g[i].pb(to);
        }
    }

    int s;
    cin >> s;
    --s;
    dp[s][0] = true;
    dfs(s, 0);

    for (int i = 0; i < n; ++i) {
        if (g[i].empty() && dp[i][1]) {
            cout << "Win\n";
            vector<int> ans;
            int curr = i;
            ans.pb(curr);
            int p = 1;
            while (!(curr == s && p == 0)) {
                curr = pr[curr][p];
                p ^= 1;
                ans.pb(curr);
            }
            reverse(all(ans));
            for (int x : ans) {
                cout << x + 1 << " ";
            }
            cout << "\n";
            return 0;
        }
    }

    color.assign(n, 0);
    dfs2(s);

    cout << (cycle ? "Draw\n" : "Lose\n");

}