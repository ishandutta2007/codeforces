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
char s[maxn];
int p;

int d(int x) { return abs(p-x); }

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d%s", &n, &p, s);
    --p;
    if (p >= n/2) p = n-p-1;

    int res = 0;
    int l = n, r = -1;
    forn(i, n/2) if (s[i] != s[n-i-1]) {
        l = min(l, i);
        r = max(r, i);
        res += min(abs(s[i] - s[n-i-1]), 26 - abs(s[i] - s[n-i-1]));
    }
    if (l == n) {
        cout << "0" << endl;
        return 0;
    }


    cout << res + (r-l) + min(d(l), d(r));
    cout << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}