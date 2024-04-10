#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4;
vector <int> g[maxn], can_dist[maxn];
bool used[maxn];
int start;

void dfs(int v){
    can_dist[start].push_back(v);
    used[v] = true;
    for (auto u : g[v]){
        if (!used[u]){
            dfs(u);
        }
    }
}

main(){
    int n, m, s, u, v;
    cin >> n >> m >> s;
    s--;
    for (int i = 0; i < m; ++i){
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
        fill(used, used + n, false);
        start = i;
        dfs(i);
    }
    set <pair <int, int> > st;
    for (int i = 0; i < n; ++i){
        bool f = true;
        for (auto u : can_dist[s]){
            if (i == u){
                f = false;
                break;
            }
        }
        if (f){
            st.insert(make_pair(can_dist[i].size(), i));
        }
    }
    /*for (int i = 0; i < n; ++i){
        for (auto u : can_dist[i]){
            cout << u << " ";
        }
        cout << endl;
    }*/
    // cout << st.size() << endl;
    while (st.size()){
        pair <int, int> elem = *st.rbegin();
        ans++;
        for (auto u : can_dist[elem.second]){
            st.erase({can_dist[u].size(), u});
        }
    }
    cout << ans;
    return 0;
}