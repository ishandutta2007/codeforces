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
#define mp make_pair

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll, int>> a(n);
    ll A, m;
    int cf, cm;
    cin >> A >> cf >> cm >> m;
    forn(i, 0, n) {
        cin >> a[i].fs;
        a[i].sn = i;
    }
    sort(all(a));
    vector<ll> s(n);
    s[0] = a[0].fs;
    forn(i, 1, n) s[i] = s[i - 1] + a[i].fs;
    int opt_i = -1;
    ll ans = -1;
    ll sum = 0, opt_sum = 0;
    ford(i, 0, n + 1) {
        if (sum > m) break;
        ll l = 0, r = A + 1;
        while (l < r - 1) {
            ll mid = (l + r) / 2;
            auto it = lower_bound(all(a), mp(mid, 0));
            int cnt = it == a.end() ? n : it - a.begin();
            if (cnt - 1 >= i) cnt = i;
            ll val = 1ll * cnt * mid - (cnt == 0 ? 0 : s[cnt - 1]);
            if (val > m - sum) r = mid;
            else l = mid;
        }
        //cerr << i << ' ' << l << '\n';
        auto it = lower_bound(all(a), mp(l, 0));
        int cnt = it == a.end() ? n : it - a.begin();
        if (cnt - 1 >= i) cnt = i;
        ll rez = 1ll * cf * (n - i) + 1ll * cm * l;
        if (rez > ans) {
            ans = rez;
            opt_i = i;
            opt_sum = sum;
        }
        
        if (i) sum += A - a[i - 1].fs;
    }
    cout << ans << '\n';
    int i = opt_i;
    sum = opt_sum;
    ll l = 0, r = A;
    while (l < r - 1) {
        ll mid = (l + r) / 2;
        auto it = lower_bound(all(a), mp(mid, 0));
        int cnt = it == a.end() ? n : it - a.begin();
        if (cnt - 1 >= i) cnt = i;
        ll val = 1ll * cnt * mid - (cnt == 0 ? 0 : s[cnt - 1]);
        if (val > m - sum) r = mid;
        else l = mid;
    }
    auto it = lower_bound(all(a), mp(l, 0));
    int cnt = it == a.end() ? n : it - a.begin();
    if (cnt - 1 >= i) cnt = i;
    for (int j = i; j < n; ++j) a[j].fs = A;
    for (int j = 0; j < cnt; ++j) a[j].fs = l;
    vector<ll> out(n);
    forn(j, 0, n) out[a[j].sn] = a[j].fs;
    forn(j, 0, n) cout << out[j] << ' ';
}