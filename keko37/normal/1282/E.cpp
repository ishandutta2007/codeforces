#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n;
int a[MAXN], b[MAXN], c[MAXN], bio[MAXN];
set <pi> st;
set <int> pos[MAXN], sus[MAXN];
vector <pi> q;
vector <int> p;

void spoji (int x, int y) {
    sus[x].insert(y); sus[y].insert(x);
}

void odspoji (int x, int y) {
    sus[x].erase(y); sus[y].erase(x);
}

void init () {
    st.clear(); q.clear(); p.clear();
    for (int i = 0; i <= n; i++) {
        pos[i].clear(); sus[i].clear();
        bio[i] = 0;
    }
}

void dfs (int x) {
    if (bio[x]) return;
    bio[x] = 1;
    p.push_back(x);
    for (auto nxt : sus[x]) dfs(nxt);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        init();
        for (int i = 0; i < n-2; i++) {
            cin >> a[i] >> b[i] >> c[i];
            pos[a[i]].insert(i);
            pos[b[i]].insert(i);
            pos[c[i]].insert(i);
        }
        for (int i = 1; i <= n; i++) {
            st.insert({pos[i].size(), i});
        }
        for (int i = 0; i < n-2; i++) {
            int x = st.begin() -> second;
            int ind = *pos[x].begin();
            st.erase({pos[a[ind]].size(), a[ind]});
            pos[a[ind]].erase(ind);
            if (!pos[a[ind]].empty()) st.insert({pos[a[ind]].size(), a[ind]});
            st.erase({pos[b[ind]].size(), b[ind]});
            pos[b[ind]].erase(ind);
            if (!pos[b[ind]].empty()) st.insert({pos[b[ind]].size(), b[ind]});
            st.erase({pos[c[ind]].size(), c[ind]});
            pos[c[ind]].erase(ind);
            if (!pos[c[ind]].empty()) st.insert({pos[c[ind]].size(), c[ind]});
            q.push_back({x, ind});
        }
        int last = q.back().second;
        spoji(a[last], b[last]); spoji(a[last], c[last]); spoji(b[last], c[last]);
        for (int i = (int) q.size() - 2; i >= 0; i--) {
            int x = q[i].first, ind = q[i].second, y, z;
            if (x == a[ind]) y = b[ind], z = c[ind];
            if (x == b[ind]) y = a[ind], z = c[ind];
            if (x == c[ind]) y = a[ind], z = b[ind];
            odspoji(y, z);
            spoji(x, y); spoji(x, z);
        }
        dfs(1);
        for (auto x : p) cout << x << " "; cout << '\n';
        for (auto par : q) cout << par.second + 1 << " "; cout << '\n';
    }
    return 0;
}