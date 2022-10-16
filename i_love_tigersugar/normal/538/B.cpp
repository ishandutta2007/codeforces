#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1<<(i))
#define BIT(x,i) (((x)>>(i))&1)
int f[MAX],trc[MAX];
int value(int mask) {
    int res=0;
    FORD(i,6,0) res=res*10+BIT(mask,i);
    return (res);
}
void prepare(void) {
    memset(f,0x3f,sizeof f);
    f[0]=0;
    FOR(i,1,MAX-1) REP(j,MASK(7)) {
        int tmp=value(j);
        if (tmp>i) break;
        if (f[i-tmp]+1<f[i]) {
            f[i]=f[i-tmp]+1;
            trc[i]=tmp;
        }
    }
}
void trace(void) {
    int n;
    scanf("%d",&n);
    printf("%d\n",f[n]);
    while (n>0) {
        printf("%d ",trc[n]);
        n-=trc[n];
    }
    printf("\n");
}
int main(void) {
    prepare();
    trace();
    return 0;
}