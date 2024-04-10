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

const int maxn = 55;

int n;
int a[maxn];
int d[maxn][maxn];
int s[maxn];
int get(int l, int r) {
    return s[r] - (l ? s[l-1] : 0);
}

int f(int l, int r) {
    if (l > r) return 0;
    if (l == r) return a[l];
    int &d = ::d[l][r];
    if (d == -1) {
        d = max(a[l] + get(l+1, r) - f(l+1, r), f(l+1, r));
    }
    return d;
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    cin >> n;
    forn(i, n) cin >> a[i];
    forn(i, n) s[i] = a[i] + (i ? s[i-1] : 0);
    memset(d, -1, sizeof(d));
    int res = f(0, n-1);
    cout << s[n-1]-res << " " << res << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}