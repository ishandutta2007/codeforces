#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
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

const int maxn = 200500;

i64 f1[maxn], f2[maxn];

void add(i64 *f, int i, i64 x) {
    if (x <= 0) return;
    for (; i < maxn; i |= (i+1)) {
        f[i] += x;
    }
}
i64 get(i64 *f, int i) {
    i64 s = 0;
    for (; i >= 0; i = (i&(i+1))-1) {
        s += f[i];
    }
    return s;
}

int n, k, a, b, q;
int cur[maxn];

int main() {
#ifdef HOME
    freopen("b.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
    forn(III, q) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int pos, x;
            scanf("%d%d", &pos, &x);
            --pos;
            int old = cur[pos];
            int nxt = min(a, cur[pos] + x);
            cur[pos] = nxt;
            add(f1, pos, min(b, nxt) - min(b, old));
            add(f2, pos, nxt - old);
        } else {
            int pos;
            scanf("%d", &pos), --pos;
            i64 r1 = pos == 0 ? 0 : get(f1, pos-1);
            i64 r2 = get(f2, n) - get(f2, pos+k-1);
//             cerr << r1 << " " << r2 << endl;
            cout << r1+r2 << "\n";
        }
    }

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}