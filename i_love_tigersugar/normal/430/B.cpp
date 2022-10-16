#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
ii a[MAX];
int m,n,k,x;
int main(void) {
    scanf("%d%d%d",&m,&k,&x);
    REP(zz,m) {
        int t;
        scanf("%d",&t);
        if (a[n].fi!=t) a[++n]=ii(t,1); else a[n].se++;
    }
    int res=0;
    FOR(i,1,n) if (a[i].fi==x && a[i].se==2) {
        int t=a[i].se;
        int j=1;
        while (i-j>=1 && i+j<=n) {
            if (a[i-j].fi!=a[i+j].fi || a[i-j].se+a[i+j].se<3) break;
            t+=a[i-j].se+a[i+j].se;
            j++;
        }
        res=max(res,t);
    }
    printf("%d",res);
    return 0;
}