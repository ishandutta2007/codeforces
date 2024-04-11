#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

vector<int> graph[maxn];
char child[maxn];
int give[maxn];
char good[maxn];

vector<int> order;
vector<int> st;
bool fail = false;

void dfs(int v) {
    if (good[v]) {
        st.push_back(v);
    }
    if (give[v] != st.back()) {
        fail = true;
    }
    for (auto u: graph[v]) {
        dfs(u);
    }
    if (good[v]) {
        st.pop_back();
        order.push_back(v);
    }
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int p, q;
        cin >> p >> q;
        child[q] = true;
        graph[p].push_back(q);
    }
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        give[i] = t;
        good[t] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!child[i]) {
            dfs(i);
        }
    }

    if (fail) {
        cout << -1 << '\n';
    } else {
        cout << order.size() << '\n';
        for (auto i: order) {
            cout << i << '\n';
        }
    }
}