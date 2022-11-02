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

int n, m, ln, lm;
int a[10];
int b[10];
int res;

void relax() {
    int x = 0;
    forn(i, ln) x = x * 7 + a[i];
    int y = 0;
    forn(i, lm) y = y * 7 + a[ln+i];
    if (x < n && y < m) {
        res++;
//         forn(i, ln) cout << a[i]; cout << ":";
//         forn(i, lm) cout << a[ln+i]; cout << endl;
    }
}

void go(int p) {
    if (p == ln+lm) {
        relax();
        return;
    }
    forn(i, 7) if (!b[i]) {
        b[i] = 1;
        a[p] = i;
        go(p+1);
        b[i] = 0;
    }
}

int main() {
#ifdef LOCAL
//     freopen("a.in", "r", stdin);
#endif

    cin >> n >> m;

    int x;
    x = 1;
    while (x < n) x *= 7, ++ln;
    ln = max(ln, 1);
    x = 1;
    while (x < m) x *= 7, ++lm;
    lm = max(lm, 1);
//     cerr << ln << " " << lm << endl;

    if (ln + lm > 7) {
        cout << 0 << endl;
        return 0;
    }

    go(0);
    cout << res << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}