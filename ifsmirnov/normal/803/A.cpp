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

int a[150][150];

void solve(int n, int k) {
    memset(a, 0, sizeof a);
    forn(i, n) if (k > 0) forn(j, n) if (j >= i && k > 0) {
        if (i == j) --k, a[i][j] = 1;
        else k -= 2, a[i][j] = a[j][i] = 1;
    }
    if (k == -1) {
        ford(i, n) ford(j, n) if (j >= i && a[i][j]) {
            assert(i != j);
            a[i][j] = 0;
            a[j][i] = 0;
            goto f;
        }
        f: forn(i, n) if (a[i][i] == 0) { a[i][i] = 1; break; }
        k = 0;
    }
    if (k) cout << -1 << endl;
    else {
        forn(i, n) {
            forn(j, n) cout << a[i][j] << " ";
            cout << "\n";
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;
    solve(n, k);
    return 0;

    fore(i, 1, 100) fore(j, 0, 100) {
        cerr << i << " " << j << endl;
        solve(i, j);
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}