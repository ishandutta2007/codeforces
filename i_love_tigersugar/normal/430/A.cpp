#include<algorithm>
#include<cstdio>
#include<vector>
#define MAX   111
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int a[MAX],b[MAX],n,m;
int main(void) {
    scanf("%d%d",&n,&m);
    REP(i,n) scanf("%d",&a[i]);
    REP(i,n) b[i]=a[i];
    sort(b,b+n);
    REP(i,n) printf("%d ",(lower_bound(b,b+n,a[i])-b)&1);
    return 0;
}