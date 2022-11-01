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
const int maxn = 150;

int k;
int e[maxn][maxn];
int n = 0;
int m = 0;

int f(int n) { return n*(n-1)*(n-2)/6; }

void relax()
{
    int t = 100;
    for (; f(t) > k; t--);
    k -= f(t);
    forn(i, t) forn(j, t) if (i != j) e[i+n][j+n] = 1;
    n += t;
    m = n;
}
bool rel1()
{
    int t = n; 
    while (t >= 2 && t*(t-1)/2 > k) --t;
    if (t == 1) return false;
    forn(i, t) e[i][m] = e[m][i] = 1;
    k -= t*(t-1)/2;
    ++m;
    return true;
}
int check()
{
    int s = 0;
    forn(i, n) forn(j, i) forn(k, j) s += e[i][j]&&e[i][k]&&e[k][j];
    return s;
}


int main()
{
    cin >> k;
    relax();
    while (k && rel1());
    n = m;
    while (k) relax();
    if (n == 0) ++n;
    cout << n << endl;
    forn(i, n) { forn(j, n) cout << e[i][j]; cout << endl; }

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}