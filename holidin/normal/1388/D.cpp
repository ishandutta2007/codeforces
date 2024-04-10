#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const int mod = 1e9 + 7;
vector <int> e[N];
int p[N], sumh[N], h[N], sump[N], a[N], b[N];
bool used[N];
vector <int> v;

void dfs(int u) {
    used[u] = 1;
    for (auto x : e[u])
    if (!used[x])
        dfs(x);
    v.push_back(u);
}


void solve() {
    int n, i, j, k;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        used[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        if (b[i] != -1)
            e[i].push_back(b[i]);
    }
    v.clear();
    for (int i = 1; i <= n; ++i)
    if (!used[i])
        dfs(i);
    int sum = 0;
    vector <int> ans, rev;
    for (int i = v.size() - 1; i >= 0; --i) {
        int x = v[i];
        sum += a[x];
        if (b[x] != 0) {
            if (a[x] >= 0) {
                a[b[x]] += a[x];
                ans.push_back(x);
            } else {
                rev.push_back(x);
            }
        } else
            ans.push_back(x);
    }
    cout << sum << "\n";
    for (auto x : ans)
        cout << x << ' ';
    for (auto x = rev.rbegin(); x != rev.rend(); ++x)
        cout << (*x) << ' ';
    cout << "\n";
}

signed main() {
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int test = 0;
    solve();
}