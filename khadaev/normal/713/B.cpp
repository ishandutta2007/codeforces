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

int n;

int get(int x1, int y1, int x2, int y2) {
    if (x2 < x1 || y2 < y1) return 0;
    cout << '?' << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    int t;
    cin >> t;
    return t;
    /*int ans = 0;
    if (x1 <= 2 && x2 >= 2 && y1 <= 2 && y2 >= 2) ++ans;
    if (x1 <= 3 && x2 >= 3 && y1 <= 4 && y2 >= 5) ++ans;
    return ans;*/
}

int dir[4][2];

bool test(int p) {
   return get(dir[0][(p >> 0) & 1], dir[1][(p >> 1) & 1], dir[2][(p >> 2) & 1], dir[3][(p >> 3) & 1]) == 1;
}

ll getSq(int p) {
    ll x1 = dir[0][(p >> 0) & 1], x2 = dir[2][(p >> 2) & 1];
    if (x1 > x2) swap(x1, x2);
    ll y1 = dir[1][(p >> 1) & 1], y2 = dir[3][(p >> 3) & 1];
    if (y1 > y2) swap(y1, y2);
    return (x2 - x1 + 1) * (y2 - y1 + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n;
    forn(i, 0, 2) {
        int l = 0, r = n;
        while (l < r - 1) {
            int m = (l + r) / 2;
            int res = get(1, 1, m, n);
            if (res > i) r = m;
            else l = m;
        }
        dir[2][i] = r;
    }
    forn(i, 0, 2) {
        int l = 1, r = n + 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            int res = get(m, 1, n, n);
            if (res > i) l = m;
            else r = m;
        }
        dir[0][i] = l;
    }
    forn(i, 0, 2) {
        int l = 0, r = n;
        while (l < r - 1) {
            int m = (l + r) / 2;
            int res = get(1, 1, n, m);
            if (res > i) r = m;
            else l = m;
        }
        dir[3][i] = r;
    }
    forn(i, 0, 2) {
        int l = 1, r = n + 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            int res = get(1, m, n, n);
            if (res > i) l = m;
            else r = m;
        }
        dir[1][i] = l;
    }
    /*forn(i, 0, 4) {
        forn(j, 0, 2) cout << dir[i][j] << ' ';
        cout << '\n';
    }*/
    ll minSq = LINF;
    int opt = -1;
    forn(p, 0, 8) {
        if (test(p) && test(p ^ 15)) {
            ll sq = getSq(p) + getSq(p ^ 15);
            if (sq < minSq) {
                minSq = sq;
                opt = p;
            }
        }
    }
    int p = opt;
    assert(p != -1);
    {
        cout << "! ";
        forn(i, 0, 4) cout << dir[i][(p >> i) & 1] << ' ';
        forn(i, 0, 4) cout << dir[i][1 - ((p >> i) & 1)] << ' ';
        cout << endl;
        return 0;
    }
}