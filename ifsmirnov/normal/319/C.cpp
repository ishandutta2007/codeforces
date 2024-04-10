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
const ld eps = 1e-14;

int n;
i64 a[maxn], b[maxn], d[maxn];

ld x[maxn];
int v[maxn];
int k;

void add(int j) {
    while (1) {
        assert(k >= 0);
        ld x = (ld)(d[v[k]] - d[j])/(ld)(b[j] - b[v[k]]);
        if (lt(x, ::x[k])) {
            --k;
        }
        else {
            ++k;
            ::x[k] = x;
            v[k] = j;
            break;
        }
    }
}

int get(ld t) {
    int l = 0, r = k+1, m;
    while (r-l > 1) {
        m = (r+l) / 2;
        if (x[m] < t)
            l = m;
        else
            r = m;
    }
    return v[l];
}

void ous()
{
    forn(i, k+1) cout << x[i] << " " << v[i] << " (" << b[v[i]] 
                 << " * x + " << d[v[i]] << ")" << endl;
    cout << "====" << endl;
}

void scan()
{
    int x;
    scanf("%d", &n);
    forn(i, n) { scanf("%d", &x); a[i] = x; }
    forn(i, n) { scanf("%d", &x); b[i] = x; }
}

void solve()
{
    k = 0;
    v[0] = 0;
    d[0] = 0;
    forn(i, n) if (i) {
        int t = get(a[i]);
        //cout << "i = " << i << endl;
        //cout << "t = " << t << endl;
        //cout << "A = " << b[t] << ", B = " << d[t] << endl;
        ld tres = (ld)a[i] * b[t] + (ld)d[t];
        if (tres < 3e18) {
            d[i] = a[i] * b[t] + d[t];
            add(i);
            //cout << i << ": " << d[i] << endl;
        }

        //cout << "----" << endl;
        //ous();
    }

    cout << d[n-1] << endl;
}



int main()
{
    //freopen("input.txt", "r", stdin);

    scan();
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}