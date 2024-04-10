#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m, k;
vector<vector<pair<int, int>>> g;
vector<vector<vector<int>>> can;
vector<vector<set<pair<int, int>>>> ban;
int ans = 0;
vector<set<int>> canhere;
ostream& operator<<(ostream& out, pair<int, int> a) {
    out << a.first << ' ' << a.second;
    return out;
}

void rec(int now) {
    if(now == k) {
        ans += canhere[now].size();
        return;
    }
    for(const auto& el : canhere[now]) {
        vector<pair<int, int>> to_add;
        for(const auto& el1 : ban[now][el]) {
            auto it = canhere[el1.first].find(el1.second);
            if(it != canhere[el1.first].end()) {
                to_add.push_back({el1.first, el1.second});
                canhere[el1.first].erase(it);
                //cout << el1 << endl;
            }
        }
        rec(now + 1);
        for(const auto& el : to_add) {
            canhere[el.first].insert(el.second);
        }
    }
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
    cin >> n >> m >> k;
    g.resize(n);
    for(int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        --v;
        --u;
        g[v].push_back({w, u});
    }
    for(int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    can.assign(n, vvi(k + 1));
    ban.assign(k + 1, vector<set<pair<int, int>>>(k + 1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            int u = g[i][j].second;
            can[u][g[i].size()].push_back(j + 1);
        }
    }
    canhere.resize(k + 1);
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= i; j++) {
            canhere[i].insert(j);
        }
    }
    for(int i = 0; i < n; i++) {
        vector<pair<int, int>> all;
        for(int j = 1; j <= k; j++) {
            unordered_set<int> here;
            for(const auto& el : can[i][j]) {
                if(here.find(el) != here.end()) {
                    auto it = canhere[j].find(el);
                    if(it != canhere[j].end()) {
                        canhere[j].erase(it);
                    }
                } else {
                    all.push_back({j, el});
                    here.insert(el);
                }
            }
        }
        if(all.empty()) {
            cout << 0;
            return 0;
        }
        for(int j = 0; j < all.size(); j++) {
            for(int l = j + 1; l < all.size(); l++) {
                if(all[j].first == all[l].first) {
                    continue;
                }
                auto p1 = all[j];
                auto p2 = all[l];
                if(p1 > p2) {
                    swap(p1, p2);
                }
                ban[p1.first][p1.second].insert(p2);
                //cout << p1 << "     "  << p2 << endl;
            }
        }
    }
    //cout << 1234 << endl;
    rec(1);
    cout << ans;
}