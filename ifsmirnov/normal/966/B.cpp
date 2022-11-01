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

const int maxn = 300500;
int n, s1, s2;
pii a[maxn];

void scan() {
    cin >> n >> s1 >> s2;
    forn(i, n) cin >> a[i].fi, a[i].se = i;
    sort(a, a+n);
}

void solve() {
    forn(III, 2) {
        for (int skip = 0; skip <= n-2; ++skip) {
            int k1 = (s1 + a[skip].fi - 1) / a[skip].fi;
            int j = skip + k1;
            if (skip + k1 >= n) continue;
            int k2 = (s2 + a[j].fi - 1) / a[j].fi;
            if (j + k2 > n) continue;
            if (III == 0) {
                cout << "Yes\n" << k1 << " " << k2 << "\n";
                forn(i, k1) cout << a[skip+i].se+1 << " "; cout << "\n";
                forn(i, k2) cout << a[j+i].se+1 << " "; cout << "\n";
            } else {
                cout << "Yes\n" << k2 << " " << k1 << "\n";
                forn(i, k2) cout << a[j+i].se+1 << " "; cout << "\n";
                forn(i, k1) cout << a[skip+i].se+1 << " "; cout << "\n";
            }
            return;
        }

        swap(s1, s2);
    }
    cout << "No\n";
}

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    scan();
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}