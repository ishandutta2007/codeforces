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

map<ll, ll> REZ(ll n) {
    map<ll, ll> steps;
    if (n == 0) return steps;
    map<ll, ll> nw;
    nw[n] = 1;
    while (!nw.empty()) {
        auto it = nw.end();
        --it;
        auto p= *it;
        nw.erase(it);
        if (p.fs == 1) continue;
        nw[p.fs / 2] += p.sn;
        nw[(p.fs + 1) / 2] += p.sn;
        steps[p.fs / 2] += p.sn;
    }
    return steps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 1 << '\n';
        return 0;
    }
    if (k == 2) {
        cout << n << '\n';
        return 0;
    }
    map<ll, ll> rez;
    map<ll, ll> nw;
    nw[n - 1] = 1;
    map<ll, ll> steps;
    while (!nw.empty()) {
        auto it = nw.end();
        --it;
        auto p= *it;
        nw.erase(it);
        if (p.fs == 1) continue;
        nw[p.fs / 2] += p.sn;
        nw[(p.fs + 1) / 2] += p.sn;
        rez[p.fs / 2] += p.sn;
        rez[(p.fs + 1) / 2] += p.sn;
        steps[p.fs / 2] += p.sn;
    }
    k -= 3;
    ll num = -1, st = -1;
    for (auto it = steps.rbegin(); it != steps.rend(); ++it) {
        if (k < it->second) {
            st = it->first;
            num = k;
            break;
        }
        k -= it->second;
    }
    //cerr << num << ' ' << st << '\n';
    ll ans = 0;
    --n;
    while (n >= 1) {
        ll lft = n / 2;
        if (lft == st) {
            if (num == 0) {
                ans += n / 2;
                break;
            } else --num;
        }
        map<ll, ll> m = REZ(lft);
        if (m[st] > num) {
            n = lft;
        } else {
            ans += lft;
            num -= m[st];
            n -= lft;
        }
    }
    cout << ans + 1 << '\n';
}