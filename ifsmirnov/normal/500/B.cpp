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

const int maxn = 310;

int n;
int a[maxn];
char c[maxn][maxn];

void fl() {
    forn(k, n) forn(i, n) forn(j, n) {
        if (c[i][k] && c[k][j]) c[i][j] = 1;
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]), --a[i];
    forn(i, n) {
        scanf("%s", c[i]);
        forn(j, n) c[i][j] -= '0';
        c[i][i] = 1;
    }
    fl();
    forn(i, n) {
        int p = i;
        for (int j = i+1; j < n; ++j) if (c[i][j] && a[j] < a[p]) p = j;
        swap(a[p], a[i]);
    }
    forn(i, n) printf("%d ", a[i]+1);
    printf("\n");

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}