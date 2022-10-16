#include<bits/stdc++.h>
#define MAX   1111
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
struct Number {
    int val[4];
    Number() {
        memset(val,0,sizeof val);
    }
    Number(char c) {
        memset(val,0,sizeof val);
        REP(i,4) if (c==i+'0') val[i]++;
    }
    Number operator + (const Number &x) const {
        Number res;
        REP(i,4) res.val[i]=val[i]+x.val[i];
        return (res);
    }
    Number operator - (const Number &x) const {
        Number res;
        REP(i,4) res.val[i]=val[i]-x.val[i];
        return (res);
    }
};
const int mod=(int)1e9+7;
char a[MAX][MAX];
int m,n;
Number up[MAX][MAX],left[MAX][MAX];
Number upLeft[MAX][MAX],upRight[MAX][MAX];
void init(void) {
    scanf("%d",&n);m=n;
    FOR(i,1,m) scanf("%s",a[i]+1);
}
void prepare(void) {
    FOR(i,1,m) FOR(j,1,n) up[i][j]=up[i-1][j]+a[i][j];
    FOR(i,1,m) FOR(j,1,n) left[i][j]=left[i][j-1]+a[i][j];
    FOR(i,1,m) FOR(j,1,n) upLeft[i][j]=upLeft[i-1][j-1]+a[i][j];
    FOR(i,1,m) FORD(j,n,1) upRight[i][j]=upRight[i-1][j+1]+a[i][j];
}
Number getPlus(int x,int y,int d) {
    return (up[x+d-1][y]-up[x-d][y]+left[x][y+d-1]-left[x][y-d]-a[x][y]);
}
Number getMul(int x,int y,int d) {
    return (upLeft[x+d-1][y+d-1]-upLeft[x-d][y-d]+upRight[x+d-1][y-d+1]-upRight[x-d][y+d]-a[x][y]);
}
bool okPlus(int x,int y,int d) {
    if (x-d+1<1 || x+d-1>m || y-d+1<1 || y+d-1>n) return (false);
    return (getPlus(x,y,d).val[0]==0);
}
bool okMul(int x,int y,int d) {
    if (x-d+1<1 || x+d-1>m || y-d+1<1 || y+d-1>n) return (false);
    return (getMul(x,y,d).val[0]==0);
}
int rangePlus(int x,int y) {
    int L=1;
    int R=max(m,n);
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (okPlus(x,y,R)?R:L);
        int M=(L+R)>>1;
        if (okPlus(x,y,M)) L=M; else R=M-1;
    }
}
int rangeMul(int x,int y) {
    int L=1;
    int R=max(m,n);
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (okMul(x,y,R)?R:L);
        int M=(L+R)>>1;
        if (okMul(x,y,M)) L=M; else R=M-1;
    }
}
int compare(const pair<int,int> &x,const pair<int,int> &y) {
    if (x.fi<y.fi) return (-compare(y,x));
    if (x==y) return (0);
    if (x.se>=y.se) return (1);
    if (x.fi==y.fi && x.se<y.se) return (-1);
    double tmp=log(2.0)*(x.fi-y.fi)-log(3.0)*(y.se-x.se);
    return ((tmp>0)-(tmp<0));
}
void process(void) {
    pair<int,int> res(-1,-1);
    FOR(x,1,m) FOR(y,1,n) if (a[x][y]!='0') {
        Number tmp=getPlus(x,y,rangePlus(x,y));
        if (compare(make_pair(tmp.val[2],tmp.val[3]),res)>0)
            res=make_pair(tmp.val[2],tmp.val[3]);
        tmp=getMul(x,y,rangeMul(x,y));
        if (compare(make_pair(tmp.val[2],tmp.val[3]),res)>0)
            res=make_pair(tmp.val[2],tmp.val[3]);
    }
    if (res.fi<0) printf("0\n");
    else {
        int tmp=1;
        REP(love,res.fi) tmp=2LL*tmp%mod;
        REP(love,res.se) tmp=3LL*tmp%mod;
        printf("%d\n",tmp);
    }
}
int main(void) {
    init();
    prepare();
    process();
    return 0;
}