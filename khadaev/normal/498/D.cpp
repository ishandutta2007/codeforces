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

const int N = 1 << 17;
const int K = 60;

int T[2 * N][K];
int a[N];

void Set(int pos, int val) {
    a[pos] = val;
    forn(i, 0, K)
        T[N + pos][i] = i % val ? 1 : 2;
}

void Relax(int i) {
    forn(j, 0, K) {
        int t = T[2 * i][j];
        T[i][j] = t + T[2 * i + 1][(j + t) % K];
    }
}

void Change(int pos, int val) {
    Set(pos, val);
    pos += N;
    pos /= 2;
    while (pos) {
        Relax(pos);
        pos /= 2;
    }
}

int Get(int l, int r) {
    l += N, r += N;
    vector<int> ls, rs;
    while (l < r) {
        if (l % 2) {
            ls.eb(l);
            ++l;
        }
        if (r % 2) {
            rs.eb(r - 1);
            --r;
        }
        l /= 2;
        r /= 2;
    }
    reverse(all(rs));
    ls.insert(ls.end(), all(rs));
    int ans = 0, res = 0;
    for (int i : ls) {
        int t = T[i][res];
        ans += t;
        res = (t + res) % K;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    forn(i, 0, n) {
        int x;
        cin >> x;
        Set(i, x);
    }
    ford(i, 1, N)
        Relax(i);
    int q;
    cin >> q;
    forn(_, 0, q) {
        char c;
        cin >> c;
        if (c == 'A') {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << Get(l, r) << '\n';
        } else {
            int x, y;
            cin >> x >> y;
            --x;
            Change(x, y);
        }
    }
}