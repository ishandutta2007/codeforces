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

const int maxn = 100500;
int n, k;
int a[maxn], r[maxn];

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    int s = 0;
    forn(i, n) scanf("%d", &a[i]), r[i] = (10 - a[i]%10)%10, s += a[i]/10;
    sort(r, r+n);
    forn(i, n) if (r[i]) {
        if (r[i] <= k) {
            k -= r[i];
            ++s;
        }
    }
    s += k/10;
    s = min(s, n*10);
    cout << s << endl;


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}