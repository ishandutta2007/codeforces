#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;
const int inf = 1e9;
const int mod = 1e9 + 7;

mt19937 rnd(58);

int bp(int x, int st) {
    if (st == 0)
        return 1;
    else if (st % 2 == 0)
            return bp((x * x) % mod, st / 2);
        else
            return (bp((x * x) % mod, st / 2) * x) % mod;
}

int l[N], r[N], t[N];
vector <pair<int, int> > v;

void solve() {
    int i, j, k, n;
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        v.push_back({l[i], 1});
        v.push_back({r[i] + 1, -1});
    }
    sort(v.begin(), v.end());
    int last = -inf, balance = 0;
    for (i = 0; i < k; ++i)
        t[i] =  0;
    t[k] = 1;
    for (i = k + 1; i <= n; ++i) {
        t[i] = (((t[i - 1] * i) % mod) * bp(i - k, mod - 2)) % mod;
    }
    int ans = 0;
    i = 0;
    while (i < v.size()) {
        j = i;
        ans = (ans + (v[i].fi - last) * t[balance]) % mod;
        while (j < v.size() && v[j].fi == v[i].fi) {
            balance += v[j].se;
            ++j;
        }
        last = v[i].fi;
        i = j;
    }
    cout << ans;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}