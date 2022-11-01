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

const int maxn = 150500;

int n, k, q;
int a[maxn];
bool cmp(int i, int j) { return a[i] > a[j]; }
vector<int> cur;

void solve() {
    scanf("%d%d%d", &n, &k, &q);
    forn(i, n) scanf("%d", &a[i]);
    forn(i, q) {
        int t, x;
        scanf("%d%d", &t, &x);
        --x;
        if (t == 1) {
            cur.pb(x);
            sort(all(cur), cmp);
            if ((int)cur.size() > k) cur.pop_back();
        } else {
            if (count(all(cur), x)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
}

int main() {
#ifdef HOME
    freopen("a.in", "r", stdin);
#endif

    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}