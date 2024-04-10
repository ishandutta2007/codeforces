#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define ld long double
#define pb push_back

vector<int> g[100000];
vector<int> st;
map<int, int> pos;
int n, m, k;
vector<bool> used, used2;

void dfs(int v, int cnt, int pr) {
    st.push_back(v);
    pos[v] = (int) st.size() - 1;
    for (auto x : g[v]) {
        if (x == pr || used2[x]) continue;
        if (pos.find(x) != pos.end()) {
            cout << 2 << endl;
            cout << (int) st.size() - pos[x] << endl;
            for (int i = pos[x]; i < st.size(); i++) cout << st[i] + 1 << " ";
            cout << endl;
            exit(0);
        }
    }
    if (cnt == k) {
        cout << 1 << endl;
        for (int i = 0; i < st.size(); i += 2) cout << st[i] + 1 << " ";
        cout << endl;
        exit(0);
    }
    for (auto x : g[v]) {
        if (x == pr || used2[x]) continue;
        dfs(x, cnt + 1, v);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    vector<int> sz(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        y--;
        x--;
        sz[x]++;
        sz[y]++;
        g[x].pb(y);
        g[y].pb(x);
    }
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) st.insert({sz[i], i});
    used.resize(n, false);
    used2.resize(n, false);
    vector<int> A;
    int cnt = n;
    while (st.size() > 0) {
        auto x = (*st.begin());
        if (x.fi != 1) break;
        st.erase(st.begin());
        int v = x.se;
        used[v] = true;
        used2[v] = true;
        cnt--;
        for (auto el : g[v]) {
            if (used[el]) used[v] = false;
            if (used2[el]) continue;
            st.erase({sz[el], el});
            sz[el]--;
            st.insert({sz[el], el});
        }
        if (used[v]) A.push_back(v);
    }
    if (cnt >= k) {
        auto x = (*st.begin()).se;
        dfs(x, 1, -1);
    }
    for (auto el : st) {
        int x = el.se;
        used[x] = true;
        for (auto v : g[x]) {
            if (used[v]) used[x] = false;
        }
        if (used[x]) A.pb(x);
    }
    cout << 1 << endl;
    for (int i = 0; i < (k + 1) / 2; i++) cout << A[i] + 1 << " ";
}