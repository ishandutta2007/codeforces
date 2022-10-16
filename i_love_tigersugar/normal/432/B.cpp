#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int h[MAX],a[MAX],c[MAX];
int n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d%d",&h[i],&a[i]);
        c[h[i]]++;
    }
    FOR(i,1,n) printf("%d %d\n",n-1+c[a[i]],n-1-c[a[i]]);
}
int main(void) {
    init();
    return 0;
}