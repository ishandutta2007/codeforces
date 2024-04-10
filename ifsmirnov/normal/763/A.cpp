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

const int maxn = 100500;

int n;
int c[maxn];
int u[maxn], v[maxn];
int d[maxn];

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    scanf("%d", &n);
    forn(i, n-1) scanf("%d%d", &u[i], &v[i]), --u[i], --v[i];
    forn(i, n) scanf("%d", &c[i]);
    int nb = 0;
    forn(i, n-1) {
        int x = u[i], y = v[i];
        if (c[x] != c[y]) ++nb, ++d[x], ++d[y];
    }

    int p = max_element(d, d+n) - d;
    if (d[p] != nb) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << p+1 << endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}