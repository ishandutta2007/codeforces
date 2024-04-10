#include<cstdio>
#define MAX   24
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
const int mod=(int)1e9+7;
int s[(1<<MAX)+7];
int f[(1<<MAX)+7];
int n,q;
int b[MAX];
void init(void) {
    scanf("%d",&n);
    int t;  
    REP(i,n) {
        scanf("%d",&t);
        s[(1<<i)]=t;
    }
    scanf("%d",&q);
    REP(i,q) scanf("%d",&b[i]);
}
void optimize(void) {
    int t;
    bool ok;    
    f[0]=1;
    s[0]=0;
    FOR(i,1,(1<<n)-1) {             
        t=i&(-i);
        s[i]=s[i^t]+s[t];
        if (s[i]>mod) s[i]=mod;     
        f[i]=0;
        ok=true;
        REP(j,q) if (s[i]==b[j]) {
            ok=false;
            break;
        }
        if (ok) REP(j,n) if ((i|(1<<j))==i) {
            f[i]+=f[i^(1<<j)];
            if (f[i]>=mod) f[i]-=mod;
        }
    }
    printf("%d",f[(1<<n)-1]);
}
int main(void) {
    init();
    optimize();
    return 0;
}