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

struct Q {
    int t, x, id;
    bool operator<(const Q& q) const {
        return x < q.x;
    }
};

const int maxn = 1000500;

int n;
vector<Q> qs[maxn];
int shr[maxn], k;
pair<int, Q> a[maxn]; // init
int res[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n) {
        int a, t, x;

        scanf("%d%d%d", &a, &t, &x);

        if (a == 1) a = 1;
        else if (a == 2) a = -1;
        else a = 0;

        ::a[i] = {x, Q{a, t, i}};
        shr[i] = x;
    }

    sort(shr, shr+n);
    k = unique(shr, shr+n) - shr;
    forn(i, n) {
        int x = lower_bound(shr, shr+k, a[i].fi) - shr;
        qs[x].push_back(a[i].se);
    }
}

int s1[maxn], k1;

int fen[maxn];
void fadd(int i, int delta) {
    for (; i < k1 + 100; i |= (i+1)) {
        fen[i] += delta;
    }
}
int fget(int i) {
    int s = 0;
    for (; i >= 0; i = (i&(i+1))-1) {
        s += fen[i];
    }
    return s;
}

void solve() {
    memset(res, -1, sizeof res);

    forn(x, k) {
        k1 = 0;
        for (Q q: qs[x]) {
            s1[k1++] = q.id;
        }
        sort(s1, s1+k1);
        k1 = unique(s1, s1+k1) - s1;
        assert(k1 == (int)qs[x].size());

        forn(i, k1) fen[i] = 0;

//         cout << "X = " << shr[x] << endl;
        sort(all(qs[x]));
        for (Q q: qs[x]) {
//             cerr << q.id << " " << q.t << endl;
            int pos = lower_bound(s1, s1+k1, q.id) - s1;
            if (q.t == 0) {
                res[q.id] = fget(pos);
            } else {
                fadd(pos, q.t);
            }
        }
    }
    forn(i, n) if (res[i] != -1) {
        printf("%d\n", res[i]);
    }
}


int main() {
#ifdef LOCAL
    freopen("e.in", "r", stdin);
#endif

    scan();
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}