#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 18;

int n, m, k;
vector<int> e[N], g[N];
int vis[N], tmr;
int r[N];
vector<int> vct;

void dfs(int v) {
    vis[v] = tmr;
    for (int to : e[v]) {
        if (vis[to] != tmr) {
            dfs(to);
        }
    }
    vct.push_back(v);
}


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    while (scanf("%d%d%d", &n, &m, &k) == 3) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
            g[i].clear();
        }
        for (int i = 0; i < n; i++) scanf("%d", &r[i]);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u; --v;
            e[u].push_back(v);
            g[v].push_back(u);
        }

        vct.clear();
        tmr++;
        for (int i = 0; i < n; i++) {
            if (vis[i] != tmr) {
                dfs(i);
            }
        }
        reverse(vct.begin(), vct.end());
        tmr++;
        bool fail = 0;
        vector<int> d(n);
        vector<int> rr(n);
        for (int i = 0; i < n; i++) rr[i] = r[i];
        for (int i = n - 1; i >= 0; i--) {
            int v = vct[i];
            int mx = 0;
            vis[v] = tmr;
            for (int to : e[v]) {
                if (vis[to] != tmr) fail = 1;
                mx = max(mx, r[to]);
                d[v] = max(d[v], d[to] + 1);
            }
            if (r[v] == 0) {
                r[v] = mx + 1;
                fail |= r[v] > k;
            } else {
                fail |= mx >= r[v];
            }
        }

        if (!fail) {
            vector<pair<int, int> > b;
            for (int i = 0; i < n; i++) b.push_back({r[i], i});
            sort(b.begin(), b.end());

            set<int> st;
            for (int i = 1; i <= k; i++) st.insert(i);
            for (int i = 0; i < n; i++) st.erase(rr[i]);
            reverse(b.begin(), b.end());
            for (auto o : b) {
                int v = o.second;
                if (rr[v] != 0) continue;
                int mn = k + 1;
                for (int to : g[v]) {
                    mn = min(mn, r[to]);
                }
                auto it = st.lower_bound(mn);
                if (it != st.begin() && *--it >= r[v]) {
                    r[v] = *it;
                    st.erase(it);
                }
            }
            fail |= !st.empty();
        }
        


        if (fail) cout << -1 << endl;
        else for (int i = 0; i < n; i++) cout << r[i] << " \n"[i + 1 == n];
    }
    
    return 0;
}