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
int a[2 * N];

int n;

void Set(int i, int v) {
    i += N;
    a[i] = v;
    i /= 2;
    while (i) {
        a[i] = a[2 * i] + a[2 * i + 1];
        i /= 2;
    }
}

int get(int l, int r) {
    int ans = 0;
    l += N, r += N;
    while (l < r) {
        if (l % 2) {
            ans += a[l];
            ++l;
        }
        if (r % 2) {
            ans += a[r - 1];
            --r;
        }
        l /= 2;
        r /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    int st = 0, sz = n;
    bool rev = false;
    forn(i, 0, n) Set(i, 1);
    while(q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            cin >> p;
            if (rev) {
                if (2 * p <= sz) {
                    sz -= p;
                    st -= p;
                    forn(i, 0, p) Set(st - i, a[N + st - i] + a[N + st + i + 1]);
                } else {
                    st -= p - 1;
                    rev = false;
                    forn(i, 0, sz - p) Set(st + i, a[N + st + i] + a[N + st - i - 1]);
                    sz = p;
                }
            } else {
                if (2 * p <= sz) {
                    sz -= p;
                    st += p;
                    forn(i, 0, p) Set(st + i, a[N + st + i] + a[N + st - i - 1]);
                } else {
                    st += p - 1;
                    rev = true;
                    forn(i, 0, sz - p) Set(st - i, a[N + st - i] + a[N + st + i + 1]);
                    sz = p;
                }
            }
            //cerr << st << ' ' << sz << ' ' << rev << '\n';
        } else {
            int l, r;
            cin >> l >> r;
            if (rev) {
                cout << get(st - r + 1, st - l + 1) << '\n';
            } else cout << get(st + l, st + r) << '\n';
        }
    }
}