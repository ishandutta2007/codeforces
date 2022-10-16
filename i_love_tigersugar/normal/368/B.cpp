#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int cnt[MAX],a[MAX];
bool ex[MAX];
int n,q;
void init(void) {
    scanf("%d",&n);
    scanf("%d",&q);
    FOR(i,1,n) scanf("%d",&a[i]);
    FORD(i,n,1) {
        cnt[i]=cnt[i+1]+1-ex[a[i]];
        ex[a[i]]=true;
    }
    REP(i,q) {
        int v;
        scanf("%d",&v);
        printf("%d\n",cnt[v]);
    }
}
int main(void) {
    init();
    return 0;
}