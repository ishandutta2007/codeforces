#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
int a[MAX],b[MAX],next[MAX];
int m,n;
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,m) scanf("%d",&b[i]);
}
void process(void) {
    int j=next[1]=0;
    FOR(i,2,m) {
        while (j>0 && b[i]-b[j+1]!=b[i-1]-b[j]) j=next[j];
        if (j==0 || b[i]-b[j+1]==b[i-1]-b[j]) next[i]=++j;
    }
    int res=0;
    j=0;
    FOR(i,1,n) {
        while (j>0 && a[i]-b[j+1]!=a[i-1]-b[j]) j=next[j];
        if (j==0 || a[i]-b[j+1]==a[i-1]-b[j]) j++;
        if (j==m) res++;
    }
    printf("%d",res);
}
int main(void) {
    init();
    process();
    return 0;
}