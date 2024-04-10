#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define int long long
using namespace std;
const int inf = 1e9;
const int N = 2e6 + 100;
const int mod = 1e9 + 7;


map <pair<int, int>, int > m;
vector <pair<int, int> > e[N];
long long c[N], sum[N];
int top, top1;
bool use[N];

int f(int x, int c) {
    if (m[{x, c}] == 0)
        m[{x, c}] = ++top1;
    return m[{x, c}];
}


void solve() {
    int i, j, k, n, a, b;
    cin >> n >> k;
    top = n;
    for (i = 1; i <= k; ++i) {
        cin >> a >> b;
        int ls = b;
        int x = i;
        vector <int> cifr;
        while (x > 0) {
            cifr.push_back(x % 10);
            x/=10;
        }
        x = i;
        int y = 0;
        while (x > 9) {
            int u = ++top;
            e[u].push_back({ls, cifr[y]});
            e[ls].push_back({u, cifr[cifr.size() - y - 1]});
            ls = u;
            x /= 10;
            ++y;
        }
        e[a].push_back({ls, cifr[cifr.size() - 1]});
        e[ls].push_back({a, cifr[0]});
    }
    vector <int> v = {1};
    c[1] = 1;
    top1 = 1;
    i = 0;
    while (i < v.size()) {
        j = i;
        while (j < v.size() && c[v[j]] == c[v[i]])
            ++j;
        for (int p = 0; p < 10; ++p)
        for (int l = i; l < j; ++l)
        for (int h = 0; h < e[v[l]].size(); ++h)
        if (e[v[l]][h].se == p && !use[e[v[l]][h].fi]) {
            use[e[v[l]][h].fi] = 1;
            v.push_back(e[v[l]][h].fi);
            c[e[v[l]][h].fi] = f(c[v[l]], p);
            sum[e[v[l]][h].fi] = (sum[v[l]] * 10 + p) % mod;
        }
        i = j;
    }
    for (i = 2; i <= n; ++i)
        cout << sum[i] << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    solve();
}