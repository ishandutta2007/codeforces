#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <cstdlib>
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
const int maxn = 1010;

int n;
int a[maxn][maxn];

int b[maxn];

void build_primary_path(int k) {
    int s = 0;
    forn(i, k) {
        int q = n++;
        int w = n++;
        int e = (i == k-1 ? 1 : n++);
        a[s][q] = a[s][w] = a[q][e] = a[w][e] = 1;
        b[i] = e;
        s = e;
    }
//     forn(i, k) cout << b[i] << " "; cout << endl;
}

int t;
int d[maxn];
int cnt[maxn];
int q[maxn];
int lq, rq;

void check() {
    forn(i, n) forn(j, n) a[i][j] |= a[j][i];
    int lq = 0, rq = 1;
    q[0] = 0;
    forn(i, n) d[i] = 100000;
    d[0] = 0;
    cnt[0] = 1;
    while (lq != rq){ 
        int v = q[lq++];
        forn(i, n) if (a[v][i]) {
            if (d[i] > d[v] + 1) {
                d[i] = d[v] + 1;
                q[rq++] = i;
            }
            if (d[i] == d[v] + 1) {
                cnt[i] += cnt[v];
            }
        }
    }
    cout << "cnt[1] = " << cnt[1] << endl;
    assert(cnt[1] == t);
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    cin >> t;
    if (t == 1) {
        cout << "2" << endl;
        cout << "NY" << endl;
        cout << "YN" << endl;
        return 0;
    }
    n = 2;
    int k = 1;
    while ((1<<(k+1)) <= t) ++k;
    build_primary_path(k);
    int s = 0;
    forn(i, k) {
        int q = n++;
        int w = n++;
        a[s][q] = a[q][w] = 1;
//         cout << "add " << s << " " << q << endl;
//         cout << "add " << q << " " << w << endl;
        s = w;
        if (t & (1<<(k-i-1))) {
//             cout << "add " << q << " " << b[i] << endl;
            a[q][b[i]] = 1;
        }
    }
    printf("%d\n", n);
    forn(i, n) {
        forn(j, n) printf("%c", "NY"[a[i][j]|a[j][i]]);
        printf("\n");
    }


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}