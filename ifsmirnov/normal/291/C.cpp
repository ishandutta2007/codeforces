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

int n, k;
u32 x[maxn];
void read() {
    scanf("%d%d", &n, &k);
    forn(i, n) {
        unsigned int a, b, c, d;
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        x[i] = (a<<24) ^ (b<<16) ^ (c<<8) ^ d;
    }
}
void solve()
{
    ford(i, 32) {
        set<int> a;
        forn(j, n) {
            //cout << ((x[j]>>i)) << " ";
            a.insert(x[j]>>i);
        }
        //cout << endl;
        if (a.size() == k) {
            //cout << a.size() << endl;
            //cout << i << endl;
            u32 t = (~0)<<i;
            printf("%d.%d.%d.%d\n", (t>>24)&255, (t>>16)&255, (t>>8)&255, t&255);
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    read();
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}