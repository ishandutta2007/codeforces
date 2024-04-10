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

const int maxn = 350;

i64 ax, bx, ay, by;
i64 a[maxn], b[maxn], c[maxn];

i64 sgn(i64 x) { return (x>0) - (x<0); }

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> ax >> ay >> bx >> by >> n;
    forn(i, n) cin >> a[i] >> b[i] >> c[i];
    int s = 0;
    forn(i, n) s += sgn(a[i]*ax + b[i]*ay + c[i]) != sgn(a[i]*bx + b[i]*by + c[i]);
    cout << s << endl;


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}