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


void solve() {
    int n;
    cin >> n;
    i64 res = 0;
    multimap<int, bool> a;
    forn(i, n) {
        int x;
        cin >> x;
        auto it = a.begin();
        if (!a.empty() && it->fi < x) {
            res += x - it->fi;
            // cerr << "put " << x << " on " << it->fi << " " << it->se << endl;
            if (!it->se) {
                a.erase(it);
            } else {
                it->se = false;
            }
            a.emplace(x, true);
        } else {
            // cerr << "add " << x << endl;
            a.emplace(x, false);
        }
    }
    cout << res << endl;
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}