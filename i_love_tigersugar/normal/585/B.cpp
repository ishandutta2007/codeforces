#include<bits/stdc++.h>
#define MAX   227
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
const char yes[]="YES";
const char no[]="NO";
char a[33][MAX];
bool f[33][MAX];
int n,m;
int x[MAX],l[MAX],r[MAX];
void init(void) {
    scanf("%d%d",&n,&m);
    memset(x,-1,sizeof x);
    memset(l,0x3f,sizeof l);
    memset(r,-1,sizeof r);
    FOR(i,1,3) scanf("%s",a[i]+1);
    FOR(i,1,3) FOR(j,1,n) if ('A'<=a[i][j] && a[i][j]<='Z') {
        minimize(l[a[i][j]-'A'],j);
        maximize(r[a[i][j]-'A'],j);
        x[a[i][j]-'A']=i;
    }
}
bool ok(int u,int v,int t) {
    REP(i,26) if (x[i]==u) {
        int L=l[i]-2*t;
        int R=r[i]-2*t;
        if (L<=v && v<=R) return (false);
    }
    return (true);
}
void process(void) {
    memset(f,false,sizeof f);
    FOR(i,1,3) if (a[i][1]=='s') f[i][1]=true;
    FOR(j,1,n-1) FOR(i,1,3) if (f[i][j]) {
        FOR(k,-1,1) if (1<=i+k && i+k<=3 && ok(i,j+1,j-1) && ok(i+k,j+1,j) && ok(i+k,j+1,j-1))
            f[i+k][j+1]=true;
    }
    bool res=false;
    FOR(i,1,3) if (f[i][n]) res=true;
    printf("%s\n",res?yes:no);
}
int main(void) {
    int t;
    scanf("%d",&t);
    REP(love,t) {
        init();
        process();
    }
    return 0;
}