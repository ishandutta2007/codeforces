#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll sum;
vector<vector<array<int, 3>>> g;
vi weight;
set<pair<ll, int>> s1, s2;
int now;
vi amount;

int dfs(int v, int p) {
    if(g[v].size() == 1 && p != -1) {
        return 1;
    }
    int am = 0;
    for(auto& u1 : g[v]) {
        int u = u1[0];
        int w = u1[1];
        int c = u1[2];
        if(u == p) continue;
        int here = dfs(u, v);
        am += here;
        int new1 = w / 2;
        weight[now++] = w;
        sum += (ll)w * here;
        amount[now - 1] = here;
        if(c == 1) {
            s1.insert({(ll)here * (w - new1), now - 1});
        } else {
            s2.insert({(ll)here * (w - new1), now - 1});
        }
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
        ll s;
        cin >> n >> s;
        sum = 0;
        g.assign(n, vector<array<int, 3>>(0));
        for(int i = 0; i < n - 1; i++) {
            int v, u, w, c;
            cin >> v >> u >> w >> c;
            --v;
            --u;
            g[v].push_back({u, w, c});
            g[u].push_back({v, w, c});
        }
        weight.resize(n - 1);
        s1.clear();
        s2.clear();
        now = 0;
        amount.resize(n);
        dfs(0, -1);
        //cout << sum << endl;
        vector<ll> can;
        ll now1 = 0;
        can.push_back(0);
        while(!s1.empty()) {
            auto it = --s1.end();
            int v = it->second;
            s1.erase(it);
            int neww = weight[v] / 2;
            now1 += (ll)amount[v] * (weight[v] - neww);
            can.push_back(now1);
            weight[v] /= 2;
            if(weight[v] != 0) {
                s1.insert({(ll)amount[v] * (weight[v] - neww / 2), v});
            }
        }
        now1 = 0;
        int ans = 1000000000;
        int it1 = 0;
        while(!s2.empty()) {
            ll need = sum - now1 - s;
            int id1 = lower_bound(can.begin(), can.end(), need) - can.begin();
            if(id1 != can.size()) {
                ans = min(ans, it1 * 2 + id1);
            }
            if(sum - now1 <= s) {
                break;
            }
            ++it1;
            auto it = --s2.end();
            int v = it->second;
            s2.erase(it);
            int neww = weight[v] / 2;
            now1 += (ll)amount[v] * (weight[v] - neww);
            weight[v] /= 2;
            if(weight[v] != 0) {
                s2.insert({(ll)amount[v] * (weight[v] - neww / 2), v});
            }
        }
        ll need = sum - now1 - s;
        int id1 = lower_bound(can.begin(), can.end(), need) - can.begin();
        if(id1 != can.size()) {
            ans = min(ans, it1 * 2 + id1);
        }
        cout << ans << '\n';
    }

}