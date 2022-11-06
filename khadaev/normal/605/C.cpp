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

ll p, q;

struct Work {
    ll a, b;

    Work () {};

    Work (ll a, ll b) : a(a), b(b) {};

    bool operator< (const Work& x) const {
        if (a * x.b != b * x.a) return a * x.b < b * x.a;
        return a < x.a;
    }

    Work operator- (Work x) {
        return Work(a - x.a, b - x.b);
    }

    ll operator^ (Work x) {
        return a * x.b - b * x.a;
    }
};

void showRatio(ll x, ll y) {
    cout << x / y << '.';
    x %= y;
    forn(i, 0, 10) {
        x *= 10;
        cout << x / y;
        x %= y;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> p >> q;
    vector<Work> x(n);
    forn(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        x[i] = Work(a, b);
    }
    sort(all(x));
    vector<Work> conv;
    int sz;
    forn(i, 0, n) {
        while ((sz = conv.size()) >= 2 && (((x[i] - conv[sz - 1]) ^ (x[i] - conv[sz - 2])) <= 0))
            conv.pop_back();
        conv.eb(x[i]);
    }
    ld ans = 1e9;
    ll pAns, qAns;
    forn(i, 0, n) {
        if (p * x[i].b > q * x[i].a) {
            ld val = (ld)p / x[i].a;
            if (val < ans) {
                ans = val;
                pAns = p;
                qAns = x[i].a;
            }
        } else {
            ld val = (ld)q / x[i].b;
            if (val < ans) {
                ans = val;
                pAns = q;
                qAns = x[i].b;
            }
        }
    }
    sz = conv.size();
    forn(i, 0, sz - 1)
        if (conv[i].a * q < conv[i].b * p && conv[i + 1].a * q > conv[i + 1].b * p) {
            ll det = conv[i].a * conv[i + 1].b - conv[i].b * conv[i + 1].a;
            ld val = ld(conv[i + 1].b * p - conv[i].b * p + conv[i].a * q - conv[i + 1].a * q) / det;
            if (val < ans) {
                ans = val;
                pAns = conv[i + 1].b * p - conv[i].b * p + conv[i].a * q - conv[i + 1].a * q;
                qAns = det;
            }
        }
    showRatio(pAns, qAns);
}