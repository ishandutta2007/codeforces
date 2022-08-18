/**
 *    author:  SPb ITMO University 1
 *    created: 16.04.2017 18:36:54       
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
typedef long double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

// !!! warning !!! not flexible epsilons in "<"
struct pt
{
    dbl x, y;
    pt(){}
    pt(dbl xx, dbl yy): x(xx), y(yy) {}
    void read() { double xx, yy; scanf("%lf%lf", &xx, &yy); x = xx, y = yy; }
};

inline pt operator + (pt p1, pt p2) { return pt(p1.x + p2.x, p1.y + p2.y); }
inline pt operator - (pt p1, pt p2) { return pt(p1.x - p2.x, p1.y - p2.y); }
inline pt operator * (pt p, dbl c) { return pt(p.x * c, p.y * c); }
inline pt operator * (dbl c, pt p) { return pt(p.x * c, p.y * c); }

inline dbl len(pt p) { return sqrt(p.x * p.x + p.y * p.y); }
inline dbl dist(pt p1, pt p2) { dbl dx = p1.x - p2.x; dbl dy = p1.y - p2.y; return sqrt(dx * dx + dy * dy); }
inline dbl scal(pt p1, pt p2) { return p1.x * p2.x + p1.y * p2.y; }
inline dbl vect(pt p1, pt p2) { return p1.x * p2.y - p1.y * p2.x; }
inline bool operator < (pt p1, pt p2) { return p1.x < p2.x - eps || (p1.x < p2.x + eps && p1.y < p2.y - eps); }


const int N = 1010;

pt a[N];




int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int n;
    scanf("%d", &n);
    forn(i, n) a[i].read();
    a[n] = a[0];
    a[n + 1] = a[1];
    dbl res = 1e100;
    for (int i = 1; i <= n; ++i)
    {
        pt v = a[i + 1] - a[i - 1];
        v = v * (1. / len(v));
        v = {-v.y, v.x};
        dbl d = abs(scal(v, a[i] - a[i - 1]));
        res = min(res, d / 2);
    }
    printf("%.10f\n", (double)res);
        
        
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}