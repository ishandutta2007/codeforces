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

const int maxn = 505 * 505;

int n;
int a[maxn];
int b[maxn];
map<int, int> rem;
int k = 0;

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);
    forn(i, n*n) scanf("%d", &a[i]);

    sort(a, a+n*n, greater<int>());
    forn(i, n*n) {
        if (rem[a[i]]) {
            --rem[a[i]];
            continue;
        }
        b[k++] = a[i];
        forn(j, k-1) {
            ++rem[__gcd(b[k-1], b[j])];
            ++rem[__gcd(b[k-1], b[j])];
        }
    }

    forn(i, k) printf("%d ", b[i]);
    printf("\n");


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}