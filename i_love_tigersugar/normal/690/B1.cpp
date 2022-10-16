#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
const char yes[]="Yes";
const char no[]="No";
char a[MAX][MAX];
int n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%s",a[i]+1);
}
bool check(int x,int y,int val) {
    if (x<1 || x>n || y<1 || y>n) return (true);
    return (a[x][y]==val+'0');
}
bool process(void) {
    bool haveFour=false;
    FOR(i,1,n) FOR(j,1,n) if (a[i][j]=='4') haveFour=true;
    if (!haveFour) return (false);
    int up=n+1;
    int down=0;
    int left=n+1;
    int right=0;
    FOR(i,1,n) FOR(j,1,n) if (a[i][j]=='4') {
        minimize(up,i);
        maximize(down,i);
        minimize(left,j);
        maximize(right,j);
    }
    if (up>down || left>right) return (false);
    FOR(i,up,down) FOR(j,left,right) if (a[i][j]!='4') return (false);
    FOR(i,up,down) if (!check(i,left-1,2)) return (false);
    FOR(i,up,down) if (!check(i,right+1,2)) return (false);
    FOR(i,left,right) if (!check(up-1,i,2)) return (false);
    FOR(i,left,right) if (!check(down+1,i,2)) return (false);
    REP(i,2) REP(j,2) {
        int x=i?up-1:down+1;
        int y=j?left-1:right+1;
        if (!check(x,y,1)) return (false);
    }
    FOR(i,1,n) FOR(j,1,n) {
        if (up-1<=i && i<=down+1 && left-1<=j && j<=right+1) continue;
        if (a[i][j]!='0') return (false);
    }
    return (true);
}
int main(void) {
    init();
    printf("%s\n",process()?yes:no);
    return 0;
}