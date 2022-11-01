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
typedef long double ld;

int n;
int l[10], r[10], len[10];

long double s;

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d%d", &l[i], &r[i]), len[i] = r[i]-l[i]+1;
}

bool in(int x, int i) { return l[i] <= x && r[i] >= x; }

void solve() {
    fore(c, 1, 10000) {
//         cout << c << endl;
        { // one
            forn(p2, n) if (in(c, p2)) forn(p1, n) if (p2 != p1 && r[p1] > c) {
                ld t = 1;
                forn(i, n) if (i != p1 && i < p2) {
                    t *= (ld)max(0, min(r[i], c) - l[i] + 1) / len[i];
                }
                forn(i, n) if (i != p1 && i > p2) {
                    t *= (ld)max(0, min(r[i], c-1) - l[i] + 1) / len[i];
                }
                t /= len[p2];
                t *= (ld)(r[p1] - max(c+1, l[p1]) + 1) / len[p1];
                s += t * c;
//                 cout << " - " << p1 << " " << p2 << " " << t << endl;
            }
        }
        { // 2+
            forn(m, 1<<n) if (__builtin_popcount(m) >= 2) {
                ld t = 1;
                bool ok = true;
                forn(i, n) if (m&(1<<i)) {
                    if (!in(c, i)) {
                        ok = false;
                        break;
                    }
                    t /= len[i];
                }
                if (!ok) continue;
                forn(i, n) if (!(m&(1<<i))) {
                    t *= (ld)max(0, min(r[i], c-1) - l[i] + 1) / len[i];
                }
                s += t * c;
//                 cout << " -- " << m << " " << t << endl;
            }
        }
    }
    printf("%.10lf\n", (double)s);
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