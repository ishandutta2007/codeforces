#include<bits/stdc++.h>
#define LOG 19
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi g;
int n, k;
vi dist;
vvi table;
vector<bool> used;
vi num;
vi l, r;
int now;

void dfs(int v, int p, int d) {
    dist[v] = d;
    table[v][0] = p;
    for(int i = 1; i < LOG; i++) {
        table[v][i] = table[table[v][i - 1]][i - 1];
    }
    for(int u : g[v]) {
        if(u == p) continue;
        dfs(u, v, d + 1);
    }
}
int dfs1(int v, int p) {
    if(used[v]) {
        return false;
    }
    if(g[v].size() == 1 && v != 0) {
        return true;
    }
    for(int u : g[v]) {
        if(u == p || used[u]) continue;
        bool res = dfs1(u, v);
        if(res) {
            return true;
        }
    }
    return false;
}

void dfs2(int v, int p) {
    if(g[v].size() == 1 && v != 0) {
        num[v] = now++;
        l[v] = num[v];
        r[v] = num[v];
        return;
    }
    l[v] = 10000000;
    r[v] = -1;
    for(int u : g[v]) {
        if(u == p) continue;
        dfs2(u, v);
        l[v] = min(l[v], l[u]);
        r[v] = max(r[v], r[u]);
    }
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first < b.first) {
        return true;
    }
    if(a.first > b.first) {
        return false;
    }
    return a.second > b.second;
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
        cin >> n >> k;
        g.assign(n, vi(0));
        vi a(k);
        for(int i = 0; i < k; i++) {
            cin >> a[i];
            --a[i];
        }
        for(int i = 0; i < n - 1; i++) { 
            int v, u;
            cin >> v >> u;
            --v;
            --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        dist.resize(n);
        table.assign(n, vi(LOG));
        dfs(0, 0, 0);
        used.assign(n, false);
        l.resize(n);
        r.resize(n);
        now = 0;
        num.resize(n);
        dfs2(0, 0);
        vector<pair<int, int>> otr;
        for(int i = 0; i < k; i++) {
            int v = a[i];
            int d = dist[v] / 2;
            for(int i = LOG - 1; i >= 0; i--) {
                if(d >= (1 << i)) {
                    d -= (1 << i);
                    v = table[v][i];
                }
            }
            otr.push_back({l[v], r[v]});
            used[v] = true;
        }
        if(dfs1(0, 0)) {
            cout << "-1\n";
        } else {
            sort(otr.begin(), otr.end(), cmp);
            int maxr = -1;
            int ans = 0;
            vector<pair<int, int>> b;
            for(int i = 0; i < otr.size(); i++) {
                if(otr[i].second <= maxr) {
                    continue;
                }
                b.push_back(otr[i]);
                maxr = otr[i].second;
            }
            maxr = -1;
            for(int i = 0; i < b.size(); i++) {
                if(b[i].first <= maxr) {
                    continue;
                }
                if(b[i].first == maxr + 1) {
                    ++ans;
                    maxr = b[i].second;
                    continue;
                }
                ++ans;
                maxr = b[i - 1].second;
            }
            if(maxr != now - 1) {
                ++ans;
            }
            cout << ans << '\n';
        }
    }
}