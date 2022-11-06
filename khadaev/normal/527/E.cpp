#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1e5 + 10;
vector<pair<int, int>> e[N];
int it[N];

const int M = 3e5 + 10;
char used[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    forn(i, 0, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        e[a].eb(b, i);
        e[b].eb(a, i);
    }
    vector<int> odd;
    forn(i, 0, n) if (e[i].size() % 2) odd.eb(i);
    assert(odd.size() % 2 == 0);
    for (int i = 0; i < (int)odd.size(); i += 2) {
        int u = odd[i], v = odd[i + 1];
        e[u].eb(v, m);
        e[v].eb(u, m++);
    }
    vector<int> st;
    st.eb(0);
    vector<int> ans;
    while (!st.empty()) {
        int u = st.back();
        while (it[u] < (int)e[u].size() && used[e[u][it[u]].sn])
            ++it[u];
        if (it[u] == (int)e[u].size()) {
            ans.eb(u);
            st.pop_back();
        } else {
            st.eb(e[u][it[u]].fs);
            used[e[u][it[u]].sn] = 1;
        }
    }
    assert((int)ans.size() == m + 1);
    cout << m + m % 2 << '\n';
    forn(i, 0, m) {
        if (i % 2 == 0) cout <<  1 + ans[i] << ' ' << 1 + ans[i + 1] << '\n';
        else cout << 1 + ans[i + 1] << ' ' << 1 + ans[i] << '\n';
    }
    if (m % 2) cout << 1 << ' ' << 1 << '\n';
}