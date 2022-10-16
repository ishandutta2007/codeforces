#include<bits/stdc++.h>
#define MAX   2228
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int n,m;
int a[MAX];
int main(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    int res=0;
    REP(zz,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        res+=min(a[u],a[v]);
    }
    printf("%d",res);
    return 0;
}