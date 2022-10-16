#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int a[MAX],b[MAX],n;
void process(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n-1) if (a[i]>a[i+1]) {
        FOR(j,i+1,n) b[j-i]=a[j];
        FOR(j,1,i) b[j+n-i]=a[j];
        bool ok=true;
        FOR(j,1,n-1) if (b[j]>b[j+1]) ok=false;
        printf("%d",ok?n-i:-1);
        return;
    }
    printf("0");
}
int main(void) {
    process();
    return 0;
}