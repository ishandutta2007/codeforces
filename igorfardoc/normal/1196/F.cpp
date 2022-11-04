#include<bits/stdc++.h>
#define inf 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<vector<pair<int, int>>> g;
vector<ll> dst;
set<int> op;

void clear_dst() {
    for(const auto& el : op) {
        dst[el] = inf;
    }
    op.clear();
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
    int n, m, k;
    cin >> n >> m >> k;
    g.resize(n);
    vector<array<int, 3>> e(m);
    for(int i = 0; i < m; i++) {
        cin >> e[i][1] >> e[i][2] >> e[i][0];
        --e[i][1];
        --e[i][2];
    }
    sort(e.begin(), e.end());
    for(int i = 0; i < min(k, m); i++) {
        g[e[i][1]].push_back({e[i][2], e[i][0]});
        g[e[i][2]].push_back({e[i][1], e[i][0]});
    }
    vector<ll> values;
    dst.assign(n, inf);
    for(int i = 0; i < n; i++) {
        clear_dst();
        op.insert(i);
        dst[i] = 0;
        set<pair<ll, int>> s;
        s.insert({0, i});
        while(!s.empty()) {
            auto it = s.begin();
            int v = it->second;
            ll dist = it->first;
            s.erase(it);
            for(auto& u1 : g[v]) {
                int u = u1.first;
                ll dstnew = u1.second + dist;
                if(dstnew < dst[u]) {
                    op.insert(u);
                    auto it = s.find({dst[u], u});
                    if(it != s.end()) {
                        s.erase(it);
                    }
                    dst[u] = dstnew;
                    s.insert({dst[u], u});
                }
            }
        }
        for(const auto& el : op) {
            if(el > i) {
                values.push_back(dst[el]);
            }
        }
    }
    sort(values.begin(), values.end());
    cout << values[k - 1];

}