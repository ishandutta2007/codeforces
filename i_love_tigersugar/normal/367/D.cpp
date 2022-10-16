#include<bits/stdc++.h>
#define MAXN   100100
#define MAXM   20
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int id[MAXN];
bool bad[(1<<MAXM)+7];
int n,m,p;
void init(void) {
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&p);
    REP(i,m) {
        int t;
        scanf("%d",&t);
        REP(j,t) {
            int v;
            scanf("%d",&v);
            id[v]=i;
        }
    }
}
int bitcount(int s) {
    int ret=0;
    REP(i,m) if ((s|(1<<i))==s) ret++;
    return (ret);
}
void findbad(void) {
    int c[MAXM+7];
    memset(c,0,sizeof c);
    FOR(i,1,n) {
        c[id[i]]++;
        if (i>p) c[id[i-p]]--;
        if (i>=p) {
            int stt=0;
            REP(j,m) if (c[j]==0) stt=stt|(1<<j);
            bad[stt]=true;
        }
    }
    int res=m;
    FORD(i,(1<<m)-1,0) {
        if (bad[i]) {
            REP(j,m) if ((i|(1<<j))==i) bad[i^(1<<j)]=true;
        }
        else res=min(res,bitcount(i));
    }
    printf("%d",res);
}
int main(void) {
    init();
    findbad();
    return 0;
}