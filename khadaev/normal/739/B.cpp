#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

typedef tree<pair<ll, int>,null_type,less<pair<ll, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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

const int N = 2e5 + 10;
int p[N];
int w[N];
int a[N];
vector<int> ch[N];
ordered_set vals[N];
ll ht[N];
int ans[N];

void dfsh(int i, ll h) {
    ht[i] = h;
    for (int j : ch[i])
        dfsh(j, h + w[j]);
}

int dfss(int i) {
    vals[i].insert({ht[i] - a[i], i});
    int ix = i;
    for (int j : ch[i]) {
        int jx = dfss(j);
        if (vals[ix].size() > vals[jx].size()) {
            for (auto t : vals[jx])
                vals[ix].insert(t);
            vals[jx].clear();
        } else {
            for (auto t : vals[ix])
                vals[jx].insert(t);
            vals[ix].clear();
            ix = jx;
        }
    }
    ans[i] = vals[ix].order_of_key({ht[i] + 1, -1}) - 1;
    return ix;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    forn(i, 0, n) cin >> a[i];
    forn(i, 1, n) {
        int x;
        cin >> x >> w[i];
        --x;
        p[i] = x;
        ch[x].eb(i);
    }
    dfsh(0, 0);
    dfss(0);
    forn(i, 0, n) cout << ans[i] << ' ';
}