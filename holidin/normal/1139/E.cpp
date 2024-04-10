#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 4e4 + 1;
const long long mod = 1e9 + 7;

vector <int> e[N];
set <pair<int, int> > edge;
int p[N], c[N], q[N], ans[N], p1[N], p2[N];
bool us[N], use[N];

bool dfs(int u) {
    use[u] = 1;
    for (int i = 0; i < e[u].size(); ++i)
    if (p2[e[u][i]] == 0) {
        p2[e[u][i]] = u;
        p1[u] = e[u][i] + 1;
        return true;
    } else if (!use[p2[e[u][i]]] && dfs(p2[e[u][i]])) {
                p2[e[u][i]] = u;
                p1[u] = e[u][i] + 1;
                return true;
            }
    return false;
}

int main() {
    int i, j, n, k, d;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; ++i)
        cin >> p[i];
    for (i = 1; i <= n; ++i)
        cin >> c[i];
    cin >> d;
    for (i = 1; i <= d; ++i) {
        cin >> q[i];
        us[q[i]] = 1;
    }
    for (i = 1; i <= n; ++i)
    if (!us[i])
        edge.insert({p[i], c[i]});
    int l = 0;
    for (i = d; i > 0; --i) {
        bool flag = true;
        while (flag) {
            while (edge.size() > 0 && (*edge.begin()).fi <= l) {
                pair <int, int> g = *edge.begin();
                edge.erase(edge.begin());
                e[g.se].push_back(g.fi);
            }
            for (j = 1; j <= k; ++j)
                use[j] = 0;
            flag = false;
            for (j = 1; j <= k; ++j)
            if (!use[j] && p1[j] == 0 && dfs(j)) {
                flag = 1;
                ++l;
            }
        }
        ans[i] = l;
        edge.insert({p[q[i]], c[q[i]]});
    }
    for (i = 1; i <= d; ++i)
        cout << ans[i] << "\n";
}