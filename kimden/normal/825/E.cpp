#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    int u, v;
    vector<vector<int>> rev(n);
    vector<int> out(n, 0);
    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        --u;
        --v;
        rev[v].push_back(u);
        ++out[u];
    }
    set<pii> st;
    for(int i = 0; i < n; ++i){
        st.insert({out[i], -i});
    }
    vector<int> ans(n);
    int label = n;
    while(!st.empty()){
        int u = -st.begin()->second;
        ans[u] = label--;
        st.erase({out[u], -u});
        for(auto v: rev[u]){
            st.erase({out[v], -v});
            --out[v];
            st.insert({out[v], -v});
        }
    }
    for(int i = 0; i < n; ++i){
        if(i){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;

    return 0;
}