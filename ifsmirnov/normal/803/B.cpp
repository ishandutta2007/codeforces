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

int n;
int a[500500];
int r[500500];

int main() {
#ifdef LOCAL
//     freopen("b.in", "r", stdin);
#endif

    cin >> n;
    forn(i, n) cin >> a[i], r[i] = n;
    int p = -n;
    forn(i, n) {
        if (a[i] == 0) p = i;
        r[i] = min(r[i], abs(i-p));
    }
    p = n*3;
    ford(i, n) {
        if (a[i] == 0) p = i;
        r[i] = min(r[i], abs(i-p));
    }
    forn(i, n) cout << r[i] << " "; cout << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}