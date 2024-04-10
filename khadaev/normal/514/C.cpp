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
const ll MOD = 1000000000039;

const ll P = 43;

ll Mod (ll x) {
    x %= MOD;
    if (x >= 0) return x;
    else return x + MOD;
}

ll Hash(string s) {
    ll ans = 0, q = 1;
    for (char c : s) {
        ans += q * ll(c - 'a' + 1);
        ans %= MOD;
        q *= P;
        q %= MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    set<ll> a;
    forn(i, 0, n) {
        string s;
        cin >> s;
        ll H = Hash(s), q = 1;
        int l = s.length();
        forn(j, 0, l) {
            ll x = s[j] - 'a' + 1;
            fore(d, 1, 3) if (d != x)
                a.insert(Mod(H - x * q + d * q));
            q *= P;
            q %= MOD;
        }
    }
    forn(i, 0, m) {
        string s;
        cin >> s;
        ll H = Hash(s);
        cout << (a.find(H) == a.end() ? "NO\n" : "YES\n");
    }
}