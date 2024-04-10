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
int t;
int a[maxn];
int b[maxn];

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &t);
    forn(i, n) scanf("%d", &a[i]);
    b[0] = 1;
    forn(i, n) if (b[i]) {
        if (i+1 == t) {
            printf("YES\n");
            return 0;
        }
        b[i+a[i]] = 1;
    }
    printf("NO\n");


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}