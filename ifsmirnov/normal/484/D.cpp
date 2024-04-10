#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

const int maxn = 1000500;

int n;
i64 a[maxn];
i64 d[maxn];
i64 smx[maxn], mmx[maxn], pmx = -1; // smx[] = i; mmx[i] = max_.. d[i-1] + a[i], pmx = -1;
i64 smn[maxn], mmn[maxn], pmn = -1;

void scan() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%lld", &a[i]);
//         a[i] += 2000000000ll;
    }
//     reverse(a, a+n);
}

void solve() {
//     forn(i, n) cout << a[i] << " "; cout << endl;
    forn(i, n) {
        if (i != 0) {
            d[i] = max(d[i], mmx[pmx] - a[i]);
            d[i] = max(d[i], mmn[pmn] + a[i]);
            d[i] = max(d[i], d[i-1]); 
        }
//         cout << i << ": " << d[i] << endl;

        while (pmx >= 0 && a[i] >= a[smx[pmx]]) {
            --pmx;
        }
        ++pmx;
        smx[pmx] = i;
        mmx[pmx] = max(pmx ? mmx[pmx - 1] : -1000000000000000000ll, (i ? d[i-1] : 0) + a[i]);
//         cout << "mx: "; forn(i, pmx+1) cout << smx[i] << " "; cout << endl;
//         cout << "mx: "; forn(i, pmx+1) cout << mmx[i] << " "; cout << endl;

        while (pmn >= 0 && a[i] <= a[smn[pmn]]) {
            --pmn;
        }
        ++pmn;
        smn[pmn] = i;
        mmn[pmn] = max(pmn ? mmn[pmn - 1] : -1000000000000000000ll, (i ? d[i-1] : 0) - a[i]);
//         cout << "mn: "; forn(i, pmn+1) cout << smn[i] << " "; cout << endl;
//         cout << "mn: "; forn(i, pmn+1) cout << mmn[i] << " "; cout << endl;
    }

    i64 res = 0, mx = a[n-1], mn = a[n-1];
    ford(i, n) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        res = max(res, mx-mn + (i ? d[i-1] : 0));
    }
    cout << res << endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}