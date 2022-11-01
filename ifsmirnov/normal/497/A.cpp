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

int n, m;
char c[maxn][maxn];

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%s", c[i]);
}

int check() {
    forn(i, n-1) {
        forn(j, m) {
            if (c[i][j] < c[i+1][j]) {
                break;
            } else if (c[i][j] > c[i+1][j]) {
                return j + 1;
            }
        }
    }
    return 0;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    int res = 0;
    while (int t = check()) {
        ++res;
        --t;
        forn(i, n) c[i][t] = 'a';
    }
    cout << res << endl;


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}