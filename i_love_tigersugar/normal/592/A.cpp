#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
const int INF=(int)1e9+7;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
char a[11][11];
bool okA(int x,int y) {
    FOR(i,1,x-1) if (a[i][y]!='.') return (false);
    return (true);
}
bool okB(int x,int y) {
    FOR(i,x+1,8) if (a[i][y]!='.') return (false);
    return (true);
}
int main(void) {
    FOR(i,1,8) scanf("%s",a[i]+1);
    int minA=INF;
    int minB=INF;
    FOR(i,1,8) FOR(j,1,8) {
        if (a[i][j]=='W' && okA(i,j)) minimize(minA,i-1);
        if (a[i][j]=='B' && okB(i,j)) minimize(minB,8-i);
    }
    printf("%c\n",minA<=minB?'A':'B');
    return 0;
}