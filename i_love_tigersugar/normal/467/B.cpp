#include<cstdio>
#define MAX   1111
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define BIT(x,i) (((x)>>(i))&1)
int n,m,k,a[MAX];
inline int diff(int x,int y) {
    int res=0;
    REP(i,n) if (BIT(x^y,i)) res++;
    return (res);
}
int main(void) {
    scanf("%d%d%d",&n,&m,&k);
    REP(i,m) scanf("%d",&a[i]);
    int res=0;
    scanf("%d",&a[m]);
    REP(i,m) if (diff(a[i],a[m])<=k) res++;
    printf("%d",res);
    return 0;
}