#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

ll c2(ll n) {return n * (n - 1) / 2;};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
	ios::sync_with_stdio(false);
	cin.tie(0);
#endif
    int n;
    cin >> n;
    map<int, int> xs, ys;
    map<pair<int, int>, int> dots;
    forn(i, 0, n) {
        int x, y;
        cin >> x >> y;
        xs[x]++;
        ys[y]++;
        dots[{x, y}]++;
    }
    ll ans = 0;
    for(auto p : xs) ans += c2(p.sn);
    for(auto p : ys) ans += c2(p.sn);
    for(auto p : dots) ans -= c2(p.sn);
    cout << ans << '\n';
	return 0;
}