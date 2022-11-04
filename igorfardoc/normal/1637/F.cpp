#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n;
vi h;
vvi g;
vi now;

pair<int, int> dfs1(int v, int p) {
    pair<int, int> mx = {-1, -1};
    for(int u : g[v]) {
        if(u == p) continue;
        mx = max(mx, dfs1(u, v));
    }
    if(mx.first == -1) {
        return {h[v], v};
    }
    if(h[v] > mx.first) {
        int delta = h[v] - mx.first;
        now[mx.second] += delta;
        mx.first = h[v];
    }
    return mx;
}

pair<int, int> dfs2(int v, int p) {
    if(p != -1) {
        pair<int, int> mx = {now[v], v};
        for(int u : g[v]) {
            if(u == p) continue;
            mx = max(mx, dfs2(u, v));
        }
        return mx;
    }
    vector<pair<int, int>> all = {{now[v], v}};
    for(int u : g[v]) {
        all.push_back(dfs2(u, v));
    }
    sort(all.begin(), all.end());
    auto p1 = all[all.size() - 2];
    if(p1.first < h[v]) {
        int delta = h[v] - p1.first;
        now[p1.second] += delta;
    }
    return {-1, -1};
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
    int n;
    cin >> n;
    g.resize(n);
    h.resize(n);
    now.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++) {
        if(g[i].size() == 1) {
            now[i] = h[i];
        }
    }
    int start = 0;
    int startam = 0;
    for(int i = 0; i < n; i++) {
        if(startam < h[i]) {
            start = i;
            startam = h[i];
        }
    }
    dfs1(start, -1);
    dfs2(start, -1);
    ll ans = 0;
    for(const auto& el : now) {
        ans += el;
    }
    cout << ans;
}