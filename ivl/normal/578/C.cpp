#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second
#define real long double

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
int a[200005];

real b[200005];
real Eval(real x){
    REP(n,i) b[i+1] = a[i] - x;
    b[0] = 0;
    REP(n,i) b[i+1] += b[i];

    real v1 = 0, v2 = 0;
    REP(n+1,i) v1 = min(v1, b[i]), v2 = max(v2, b[i]);

    return v2 - v1;
}

int main(){
    scanf("%d", &n);
    REP(n,i) scanf("%d", a+i);
    real lo = -2000000, hi = 2000000, m1, m2;
    REP(200,i){
        m1 = (lo * 2 + hi) / 3;
        m2 = (lo + hi * 2) / 3;
        real v1 = Eval(m1), v2 = Eval(m2);
        if (v1 > v2) lo = m1;
        else hi = m2;
    } printf("%.12lf\n", (double)Eval(lo));
    return 0;
}