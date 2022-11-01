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
const int sz = 1<<17;
const int maxn = 100500;

pii rmq[sz*2];
pii get(int l, int r) {
    l += sz;
    r += sz;
    pii mx = mp(-1, -1);
    while (l < r) {
        if (l%2 == 1) mx = max(mx, rmq[l]);
        if (r%2 == 0) mx = max(mx, rmq[r]);
        l = (l+1)/2;
        r = (r-1)/2;
    }
    if (l == r) mx = max(mx, rmq[l]);
    return mx;
}
void upd(int i, pii x) {
    i += sz;
    rmq[i] = x;
    for (i /= 2; i; i /= 2) {
        rmq[i] = max(rmq[i*2], rmq[i*2+1]);
    }
}

int n;
i64 d;
i64 a[maxn];
i64 shr[maxn];
int anc[maxn];
int res[maxn];
int k;

void scan() {
    scanf("%d%lld", &n, &d);
    forn(i, n) {
        scanf("%lld", &a[i]);
        shr[i] = a[i];
    }
    sort(shr, shr+n);
    k = unique(shr, shr+n) - shr;
}

pii get_bounds(i64 x) {
    int l = upper_bound(shr, shr+k, x-d) - shr - 1;
    int r = lower_bound(shr, shr+k, x+d) - shr;
    return mp(l, r);
}

void solve() {
    forn(i, n) anc[i] = -1;
    forn(i, k) upd(i, mp(-1, -1));
    forn(i, n) {
        pii b = get_bounds(a[i]);
        pii mx = mp(-1, -1);
        mx = max(mx, get(0, b.fi));
        mx = max(mx, get(b.se, k-1));
        if (mx.se != -1) {
            anc[i] = mx.se;
            res[i] = mx.fi + 1;
        } else {
            anc[i] = -1;
            res[i] = 1;
        }
        upd(lower_bound(shr, shr+k, a[i]) - shr, mp(res[i], i));
    }

    int t = max_element(res, res+n) - res;
    vi res;
    while (t != -1) {
        res.pb(t);
        t = anc[t];
    }
    reverse(all(res));
    printf("%d\n", (int)res.size());
    for (auto x: res) {
        printf("%d ", x+1);
    }
    printf("\n");
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