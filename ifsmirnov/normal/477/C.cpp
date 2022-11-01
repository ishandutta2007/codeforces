#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
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

const int maxn = 2010;

int n, m;
char s[maxn], p[maxn];
int nxt[maxn], cost[maxn];
int d[maxn][maxn];

void scan() {
    scanf("%s%s", s, p);
    n = strlen(s);
    m = strlen(p);
}

void precomp() {
    forn(i, n) nxt[i] = -1;
    forn(i, n-m+1) {
        int l = i, r = 0;
        while (l < n && r < m) {
            if (s[l] == p[r]) {
                ++l;
                ++r;
            } else {
                ++l;
                ++cost[i];
            }
        }
        if (r == m) {
            nxt[i] = l;
        }
    }
}

void solve() {
    precomp();
//     forn(i, n) cout << nxt[i] << " "; cout << endl;
//     forn(i, n) cout << cost[i] << " "; cout << endl;
    forn(i, n) fore(x, 0, i) {
        d[i+1][x] = max(d[i][x], d[i+1][x]);
        d[i+1][x+1] = max(d[i][x], d[i+1][x+1]);
        if (nxt[i] != -1) {
            d[nxt[i]][x+cost[i]] = max(d[nxt[i]][x+cost[i]], d[i][x] + 1);
        }
    }
    fore(i, 0, n) {
        printf("%d%c", d[n][i], " \n"[i == n]);
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