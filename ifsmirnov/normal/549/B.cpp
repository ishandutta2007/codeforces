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

const int maxn = 105;

int n;
int a[maxn][maxn];
int c[maxn];
int b[maxn];
vi e[maxn], f[maxn];
char buf[maxn];
int r[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%s", buf);
        forn(j, n) {
            a[i][j] = buf[j] - '0';
            if (a[i][j]) e[j].pb(i), f[i].pb(j);
        }
    }
    forn(i, n) scanf("%d", &r[i]);
}

int order[maxn];

void solve() {
    forn(i, n) order[i] = i;
    random_shuffle(order, order+n);
    bool fail = true;
    int iter = 0;
    while (fail) {
        if (++iter == 100) {
            if (clock() > CLOCKS_PER_SEC * 0.8) {
                cout << -1 << endl;
                return;
            }
            iter = 0;
            random_shuffle(order, order+n);
        }
        fail = false;
        int k = -1;
        forn(i, n) if (c[order[i]] == r[order[i]]) {
            fail = true;
            k = order[i];
            break;
        }
        if (!fail) break;
        int rr = k;
//         int rr = e[k][rand()%e[k].size()];
        for (auto to: f[rr]) c[to] += (b[rr] ? -1 : 1);
        b[rr] ^= 1;
        assert(c[k] != r[k]);
    }

    cout << count(b, b+n, 1) << endl;
    forn(i, n) if (b[i]) cout << i+1 << " ";
    cout << endl;
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