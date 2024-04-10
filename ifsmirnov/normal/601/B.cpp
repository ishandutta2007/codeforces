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

const int maxn = 100500;

int n, q;
int prv[maxn], nxt[maxn], a[maxn], b[maxn];
int st[maxn];

void scan() {
    scanf("%d%d", &n, &q);
    forn(i, n) scanf("%d", &b[i]);
    forn(i, n-1) a[i] = abs(b[i] - b[i+1]);
//     forn(i, n-1) cout << a[i] << " "; cout << endl;
}

void buildPrv() {
    int sp = -1;
    forn(i, n) {
        while (sp >= 0 && a[st[sp]] < a[i]) --sp;
        if (sp == -1) prv[i] = -1;
        else prv[i] = st[sp];
        st[++sp] = i;
    }
}

void buildNxt() {
    int sp = -1;
    ford(i, n) {
        while (sp >= 0 && a[st[sp]] <= a[i]) --sp;
        if (sp == -1) nxt[i] = n-1;
        else nxt[i] = st[sp];
        st[++sp] = i;
    }
}

void solve() {
    buildPrv();
    buildNxt();
//     forn(i, n-1) cout << prv[i] << " "; cout << endl;
//     forn(i, n-1) cout << nxt[i] << " "; cout << endl;

    forn(EQEW, q) {
        int l, r;
        scanf("%d%d", &l, &r);
        l -= 1;
        r -= 2;
        i64 s = 0;
        for (int i = l; i <= r; ++i) {
            int lp = max(l-1, prv[i]);
            int rp = min(r+1, nxt[i]);
//             cout << a[i] << ": " << lp << " " << rp << endl;
            s += (i64)(i-lp) * (rp-i) * a[i];
        }
        cout << s << "\n";
    }
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