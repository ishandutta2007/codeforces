/**
 *    author:  [itmo] enot.1.10
 *    created: 18.03.2017 18:51:58       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

const int N = 88;

char s[N];

vector<pi> V, K, X;
int n;

int mem[N][N][N][2];
char t[N];

int go(int cv, int ck, int cx, int lastv)
{
    int pos = cv + ck + cx;
    if (pos == n)
    {
        //eprintf("%s\n", t);
        return 0;
    }
    int &res = mem[cv][ck][cx][lastv];
    if (res != -1) return res;

    res = inf;
    if (cv < sz(V))
    {
        t[pos] = 'V';
        res = min(res, go(cv + 1, ck, cx, 1) + abs(V[cv].F - ck) + abs(V[cv].S - cx));
    }
    if (ck < sz(K) && !lastv)
    {
        t[pos] = 'K';
        res = min(res, go(cv, ck + 1, cx, 0) + abs(K[ck].F - cv) + abs(K[ck].S - cx));
    }
    if (cx < sz(X))
    {
        t[pos] = 'X';
        res = min(res, go(cv, ck, cx + 1, 0) + abs(X[cx].F - cv) + abs(X[cx].S - ck));
    }
    return res;
}

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    memset(mem, -1, sizeof mem);
    scanf("%d", &n);
    scanf("%s", s);
    forn(i, n)
    {
        if (s[i] == 'V') V.pb({sz(K), sz(X)});
        else if (s[i] == 'K') K.pb({sz(V), sz(X)});
        else X.pb({sz(V), sz(K)});
    }
    int res = go(0, 0, 0, 0) / 2; 
    printf("%d\n", res);

        
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}