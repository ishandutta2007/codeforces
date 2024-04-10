#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

int n, A, M;
vector<pii> al, mo;

int go(const vector<pii>& a, int M) {
    int p = 0, mx = -1;
    int res = -1;
    vi pref{-1};
    forn(i, a.size()) {
        int x = max(pref.back(), a[i].se);
        pref.pb(x);
    }
    for (int i = a.size()-1; i >= 0; --i) {
        p = min(p, i);
        while (p < i && a[p].fi + a[i].fi <= M) {
            mx = max(mx, a[p].se);
            ++p;
        }
        if (pref[p] != -1) res = max(res, pref[p] + a[i].se);
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    cin >> n >> M >> A;
    int ma = -1, mm = -1;
    forn(i, n) {
        int x, c;
        char t;
        cin >> x >> c >> t;
        if (t == 'C') mo.pb({c, x});
        else al.pb({c, x});

        if (t == 'C' && c <= M) mm = max(mm, x);
        if (t == 'D' && c <= A) ma = max(ma, x);
    }

    sort(all(al));
    sort(all(mo));

    int res = -1;

    if (ma != -1 && mm != -1) res = ma+mm;
    res = max(res, go(al, A));
    res = max(res, go(mo, M));

    cout << max(res, 0) << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}