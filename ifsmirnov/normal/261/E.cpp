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
const int maxn = 3000000;

const int sz = 8388608;
int fl = 0;
int ht[sz];
char val[sz];
inline int mhash(int x)
{
    //return abs((x*10099) ^ (x*434342))%sz;
    return ((x*10099) ^ (x<<5))&(sz-1);
}
void init()
{
    forn(i, sz) ht[i] = -1;
}
inline char& get(int x)
{
    int i = mhash(x);
    while (ht[i] != -1 && ht[i] != x)
        i = (i+1)%sz;
    fl += ht[i] == -1;
    ht[i] = x;
    return val[i];
}

int bufa[maxn*2], bufb[maxn*2];
int *cura = bufa, *nxta = bufa+maxn;
int *curb = bufb, *nxtb = bufb+maxn;
int curc=0, nxtc=0;

void iterate()
{
    nxtc = 0;
    forn(i, curc)
    {
        int a = cura[i];
        int b = curb[i];
        char &t = get(a);
        if (t < b+1)
        {
            t = b+1;
            if ((i64)a*(b+1) <= 1000000000)
            {
                nxta[nxtc] = a;
                nxtb[nxtc++] = b+1;
            }
        }
        if (a < 10000000 || (i64)a*b <= 1000000000)
        {
            char &t = get(a*b);
            if (t < b)
            {
                t = b;
                nxta[nxtc] = a*b;
                nxtb[nxtc++] = b;
            }
        }
    }
    swap(curc, nxtc);
    swap(cura, nxta);
    swap(curb, nxtb);
}


int main()
{
    init();

    curc = 1;
    cura[0] = 1;
    curb[0] = 0;

    int l, r, p;
    cin >> l >> r >> p;
    forn(i, p)
        iterate();
    int s = 0;
    forn(i, sz)
        if (ht[i] >= l && ht[i] <= r)
            ++s;
    cout << s << endl;

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}