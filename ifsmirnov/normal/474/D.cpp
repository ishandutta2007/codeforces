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
const int mod = 1000000007;
int add(int x, int y) { return (x+y)%mod; }
int sub(int x, int y) { return ((i64)x-y+mod)%mod; }
const int maxn = 100500;

int t, k;
i64 d[maxn], s[maxn];

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d", &t, &k);
    d[0] = 1;
    s[0] = 1;
    forn(i, 100500) if (i) {
        d[i] += d[i-1];
        if (i >= k) d[i] += d[i-k];
        d[i] %= mod;
        s[i] = s[i-1] + d[i];
        s[i] %= mod;
    }
    forn(i, t) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", sub(s[r], s[l-1]));
    }


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}