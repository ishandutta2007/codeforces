#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll sum;
vector<vector<pair<int, int>>> g;
vi weight;
set<pair<ll, int>> s;
int now;
vi amount;

int dfs(int v, int p) {
    if(g[v].size() == 1 && p != -1) {
        return 1;
    }
    int am = 0;
    for(auto& u1 : g[v]) {
        int u = u1.first;
        int w = u1.second;
        if(u == p) continue;
        int here = dfs(u, v);
        am += here;
        int new1 = w / 2;
        weight[now++] = w;
        sum += (ll)w * here;
        amount[now - 1] = here;
        s.insert({(ll)here * (w - new1), now - 1});
    }
    return am;
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
        int n;
        ll s1;
        cin >> n >> s1;
        sum = 0;
        g.assign(n, vector<pair<int, int>>(0));
        for(int i = 0; i < n - 1; i++) {
            int v, u, w;
            cin >> v >> u >> w;
            --v;
            --u;
            g[v].push_back({u, w});
            g[u].push_back({v, w});
        }
        weight.resize(n - 1);
        s.clear();
        now = 0;
        amount.resize(n);
        dfs(0, -1);
        //cout << sum << endl;
        int ans = 0;
        while(sum > s1) {
            auto it = --s.end();
            int v = it->second;
            s.erase(it);
            int neww = weight[v] / 2;
            sum -= (ll)amount[v] * (weight[v] - neww);
            weight[v] /= 2;
            s.insert({(ll)amount[v] * (weight[v] - neww / 2), v});
            ++ans;
        }
        cout << ans << '\n';
    }

}