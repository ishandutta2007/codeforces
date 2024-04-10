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

bool ff(vi& a) {
    forn(i, a.size()-1) {
        if (a[i+1] > a[i]+1) { a[i+1]--; a[i]++; return true; }
        if (a[i] > a[i+1]+1) { a[i]--; a[i+1]++; return true; }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    vi b;

    vi t(a);
    sort(all(t));

    forn(i, n) {
        if (ff(a)) { cout << "NO\n"; return 0; }
        auto it = max_element(all(a));
        b.push_back(*it);
        a.erase(it);
    }
    reverse(all(b));
    assert(b == t);
    if (b == t) cout << "YES\n";
    else cout << "NO\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}