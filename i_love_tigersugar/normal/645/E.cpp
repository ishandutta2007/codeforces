#include<bits/stdc++.h>
#define MAX   2000200
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
int n,m,q;
char t[MAX];
int prev[MAX],sum[MAX];
void init(void) {
    scanf("%d%d",&n,&q);
    scanf("%s",t+1);
    m=strlen(t+1);
}
void process(void) {
    sum[0]=1;
    FOR(i,1,m) {
        sum[i]=(2*sum[i-1]%mod-(prev[t[i]]==0?0:sum[prev[t[i]]-1])+mod)%mod;
        prev[t[i]]=i;
    }
    FOR(i,m+1,m+n) {
        int best='a';
        REP(j,q) if (prev['a'+j]<prev[best]) best='a'+j;
        sum[i]=(2*sum[i-1]%mod-(prev[best]==0?0:sum[prev[best]-1])+mod)%mod;
        prev[best]=i;
    }
    printf("%d\n",sum[m+n]);
}
int main(void) {
    init();
    process();
    return 0;
}