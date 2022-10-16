#include<bits/stdc++.h>
#define MAXN   227
#define MAXD   1111
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
const int mod=(int)1e9+7;
int a[MAXN],sum[MAXN],n,allow;
int f[MAXN][MAXN][MAXD];
void init(void) {
    scanf("%d%d",&n,&allow);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    FOR(i,1,n) sum[i]=sum[i-1]+a[i];
}
void update(int pos,int num,int curVal,int toUpdate) {
    if (pos+num>n) return;
    int tmp=curVal+sum[pos+num]-sum[pos];
    if (tmp<0 || tmp>allow) return;
    f[pos][num][tmp]+=toUpdate;
    if (f[pos][num][tmp]>=mod) f[pos][num][tmp]-=mod;
}
void optimize(void) {
    f[0][0][0]=1;
    REP(pos,n) REP(num,n+1) REP(tmp,allow+1) if (pos+num<=n && f[pos][num][tmp]>0) {
        int curVal=tmp-(sum[pos+num]-sum[pos]);
        if (num>0) update(pos+1,num,curVal,1LL*f[pos][num][tmp]*num%mod);
        update(pos+1,num,curVal,f[pos][num][tmp]);
        update(pos+1,num+1,curVal-a[pos+1],f[pos][num][tmp]);
        if (num>0) update(pos+1,num-1,curVal+a[pos+1],1LL*f[pos][num][tmp]*num%mod);
    }
    int res=0;
    REP(i,allow+1) res=(res+f[n][0][i])%mod;
    printf("%d\n",res);
}
int main(void) {
    init();
    optimize();
    return 0;
}