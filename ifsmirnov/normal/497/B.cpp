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

int n;
int a[maxn];
int s[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", &a[i]);
        --a[i];
        s[i] = a[i];
        if (i) s[i] += s[i-1];
    }
}

void rcan() {
    n = rand()%100000 + 1;
    forn(i, n) {
        a[i] = (rand()%10 == 0) + 1;
        --a[i];
        s[i] = a[i];
        if (i) s[i] += s[i-1];
    }
}

int get(int l, int r) {
    assert(r < n);
    assert(l <= r);
    return s[r] - (l ? s[l-1] : 0);
}

int mm(int l, int r) {
    if (r < l) {
        return 0;
    }
    int t = get(l, r);
    return max(t, (r-l+1) - t);
}

int getp(int st, int t) {
    if (mm(st, n-1) < t) {
        return -1;
    }
    int l = st-1, r = n-1, m;
    while (r-l>1) {
        m = (r+l)/2;
        if (mm(st, m) >= t) {
            r = m;
        } else {
            l = m;
        }
    }
    assert(mm(st, r) == t && mm(st, l) < t);
    assert(get(st, r) * 2 != r-st+1);
    return r;
}

void solve() {
    vector<pii> res;
    fore(t, 1, n) {
        int i = 0;
        int s1 = 0, s2 = 0;
        int mx = 0;
        while (i < n) {
            int j = i;
            i = getp(i, t);
            mx = max(s1, s2);
            if (i == -1) {
                s1 = s2;
                break;
            } else {
                if (get(j, i) == t) {
                    ++s1;
                } else {
                    assert(get(j, i) + t == i-j+1);
                    ++s2;
                }
                ++i;
            }
        }
        if (s1 != s2 && max(s1, s2) != mx) {
            res.pb(mp(max(s1, s2), t));
        }
    }
    sort(all(res));
    printf("%d\n", (int)res.size());
    forn(i, res.size()) {
        printf("%d %d\n", res[i].fi, res[i].se);
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

//     while (true) { rcan(); solve(); }
    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}