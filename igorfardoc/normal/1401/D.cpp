#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n;
vvi g;
vector<ll> ans;

int dfs(int v, int p) {
    int sz = 1;
    for(int u : g[v]) {
        if(u == p) continue;
        int here = dfs(u, v);
        ans.push_back((ll)here * (n - here));
        sz += here;
    }
    return sz;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        g.assign(n, vi(0));
        for(int i = 0; i < n - 1; i++) {
            int v, u;
            cin >> v >> u;
            --v;
            --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        ans.clear();
        dfs(0, -1);
        sort(ans.begin(), ans.end());
        int m;
        cin >> m;
        vi p(m);
        for(int i = 0; i < m; i++) {
            cin >> p[i];
        }
        for(int i = 0; i < n - 1 - m; i++) {
            p.push_back(1);
        }
        sort(p.begin(), p.end());
        int res = 0;
        int last = 1;
        for(int i = n - 2; i < p.size(); i++) {
            last = ((ll)last * p[i]) % mod;
        }
        res = ans[n - 2] % mod * last % mod;
        for(int i = 0; i < n - 2; i++) {
            res = (ans[i] % mod * p[i] % mod + res) % mod;
        }
        cout << res << '\n';
    }
}