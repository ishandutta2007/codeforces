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

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
    int x = 0;
    forn(i, n) x = __gcd(x, a[i]);
    forn(i, n) {
        int t = a[i] / x;
        while (t%2 == 0) t /= 2;
        while (t%3 == 0) t /= 3;
        if (t != 1) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");

#   ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}