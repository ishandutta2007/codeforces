#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
#define le(x, y) ((x)<=(y)+eps)
#define gt(x, y) ((x)>(y)+eps)
#define ge(x, y) ((x)>=(y)-eps)
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9+100500;
const int maxn = 100500;

int n;
int a[maxn];

int solve()
{
    if (n%2 == 1) {
        int res = 0;
        forn(i, n*2-1) res += abs(a[i]);
        return res;
    }
    else {
        sort(a, a+n*2-1);
        int s = 0;
        forn(i, n*2-1) s += a[i];
        int mx = s;
        forn(i, n-1) {
            s -= 2*a[i*2];
            s -= 2*a[i*2+1];
            mx = max(mx, s);
        }
        return mx;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    cin >> n;
    forn(i, n*2-1) cin >> a[i];

    cout << solve() << endl;

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}