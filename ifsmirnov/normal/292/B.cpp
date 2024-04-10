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

int n, m;
int d[maxn], c[maxn];

void solve()
{
    cin >> n >> m;
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        ++d[x-1]; ++d[y-1];
    }
    forn(i, n) ++c[d[i]];

    if (n == m && c[2] == n)
        cout << "ring topology" << endl;
    else if (n == m+1 && c[1] == 2 && c[2] == n-2)
        cout << "bus topology" << endl;
    else if (n == m+1 && c[1] == n-1 && c[n-1] ==1) 
        cout << "star topology" << endl;
    else
        cout << "unknown topology" << endl;
}

int main()
{
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}