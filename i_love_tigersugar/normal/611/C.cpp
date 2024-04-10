#include<bits/stdc++.h>
#define MAX   555
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
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
char a[MAX][MAX];
int cntHor[MAX][MAX],cntVer[MAX][MAX];
int m,n;
bool ok(int x,int y) {
    if (x<1 || x>m || y<1 || y>n) return (false);
    return (a[x][y]=='.');
}
bool canPutHor(int x,int y) {
    return (ok(x,y) && ok(x,y+1));
}
bool canPutVer(int x,int y) {
    return (ok(x,y) && ok(x+1,y));
}
void init(void) {
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",a[i]+1);
}
void prepare(void) {
    FOR(i,1,m) FOR(j,1,n) {
        cntHor[i][j]=cntHor[i][j-1]+cntHor[i-1][j]-cntHor[i-1][j-1]+canPutHor(i,j);
        cntVer[i][j]=cntVer[i][j-1]+cntVer[i-1][j]-cntVer[i-1][j-1]+canPutVer(i,j);
    }
}
int getSum(int cnt[][MAX],int x1,int y1,int x2,int y2) {
    if (x1>x2 || y1>y2) return (0);
    return (cnt[x2][y2]-cnt[x1-1][y2]-cnt[x2][y1-1]+cnt[x1-1][y1-1]);
}
int answer(int x1,int y1,int x2,int y2) {
    return (getSum(cntHor,x1,y1,x2,y2-1)+getSum(cntVer,x1,y1,x2-1,y2));
}
void process(void) {
    int q;
    scanf("%d",&q);
    REP(love,q) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",answer(x1,y1,x2,y2));
    }
}
int main(void) {
    init();
    prepare();
    process();
    return 0;
}