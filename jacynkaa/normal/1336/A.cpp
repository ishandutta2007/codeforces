#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).S())
#define what(x) cerr << #x << " is " << x << endl;
#define int long long

const int MAXN = 1e6;

vector<int> G[MAXN];
int depth[MAXN];
int S[MAXN];
vector<int> val;

void dfs(int x, int p = -1)
{
    for (int y : G[x])
        if (y != p)
        {
            depth[y] = depth[x] + 1;
            dfs(y, x);
            S[x] += S[y];
        }
    val.push_back(depth[x] - S[x]);
    // cerr << x + 1 << " " << depth[x] - S[x] << endl;
    S[x] += 1;
}

int32_t main()
{
    _upgrade;
    int n, k;
    cin >> n >> k;
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        G[--u].push_back(--v);
        G[v].push_back(u);
    }
    dfs(0);
    sort(all(val), greater<int>());
    int res = 0;
    rep(i, k)
        res += val[i];
    cout << res << endl;
}