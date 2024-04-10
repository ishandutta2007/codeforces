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
const int maxn = 100500;

const int sz = 1<<17;
int a[sz*2];
void upd(int l, int r, int x) {
    l += sz;
    r += sz;
    while (l < r) {
        if (l%2 == 1) a[l] |= x;
        if (r%2 == 0) a[r] |= x;
        l = (l+1)/2;
        r = (r-1)/2;
    }
    if (l == r) a[l] |= x;
}
int getv(int i) {
    i += sz;
    int x = 0;
    for (; i; i /= 2) x |= a[i];
    return x;
}
void upd(int i, int x) {
    i += sz;
    a[i] = x;
    for (i /= 2; i; i /= 2) a[i] = a[i*2] & a[i*2+1];
}
int get(int l,  int r) {
    l += sz;
    r += sz;
    unsigned x = ~0;
    while (l < r) {
        if (l%2 == 1) x &= a[l];
        if (r%2 == 0) x &= a[r];
        l = (l+1)/2;
        r = (r-1)/2;
    }
    if (l == r) x &= a[l];
    return x;
}

int b[maxn], q[maxn], l[maxn], r[maxn];

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    forn(i, m) {
        scanf("%d%d%d", &l[i], &r[i], &q[i]);
        upd(l[i]-1, r[i]-1, q[i]);
    }
    forn(i, n) b[i] = getv(i);
    forn(i, sz*2) a[i] = ~0;
    forn(i, n) upd(i, b[i]);
    forn(i, m) if (get(l[i]-1, r[i]-1) != q[i]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    forn(i, n) printf("%d ", b[i]);
    printf("\n");


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}