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

const int maxn = 200500;
int n;
int a[maxn];
int root;
int cnt[maxn];

void solve() {
    cin >> n >> root, --root;
    forn(i, n) cin >> a[i];

    forn(i, n) {
        if (a[i] && i != root) ++cnt[a[i]];
    }

    int best = n-1;
    int skip = 0;
    int right = n-1;
    for (int val = 1; val <= n-1; ++val) {
        if (!cnt[val]) ++skip;
        right -= cnt[val];

        best = min(best, max(right, skip));
    }

    if (a[root] != 0) ++best;
    cout << best << endl;
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}