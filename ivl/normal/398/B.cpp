#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define x first
#define y second
#define ll long long
#define pii pair < int, int >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
double Exp(int x, int y){
    static double memo[2005][2005];
    static bool bio[2005][2005];

    if (x > y) swap(x, y);
    double &r = memo[x][y];
    if (bio[x][y]++) return r;
    if (y == 0) return r = 0;
    if (x == 0) r = Exp(0, y-1) + (double)n/y;
    else r = (n*n + Exp(x-1, y)*x*(n-y) + Exp(x, y-1)*(n-x)*y + Exp(x-1, y-1)*x*y) / (n*x + n*y - x*y);
    return r;
}

int main(){
    int m;
    scanf("%d%d", &n, &m);
    vector < bool > v1(n, true), v2(n, true);
    REP(m,i){
        int r, c;
        scanf("%d%d", &r, &c), --r, --c;
        v1[r] = v2[c] = false;
    }
    int x = 0, y = 0;
    REP(n,i) x += v1[i], y += v2[i];
    printf("%.12lf\n", Exp(x,y));
    return 0;
}