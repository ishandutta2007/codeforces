#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int main(void) {
    int n,m;
    scanf("%d%d",&n,&m);
    int k=n-1;
    if ((m+1)/2<=k && k<=m) {
        int n1=0;
        REP(i,k) {
            printf("0");
            REP(j,1+(n1<m-k)) printf("1");
            n1++;
        }
        printf("0");
        return 0;
    }
    k=n;
    if ((m+1)/2<=k && k<=m) {
        int n1=0;
        REP(i,k) {
            printf("0");
            REP(j,1+(n1<m-k)) printf("1");
            n1++;
        }
        return 0;
    }
    k=n+1;
    if ((m+1)/2<=k && k<=m) {
        int n1=0;
        REP(i,k) {
            if (i>0) printf("0");
            REP(j,1+(n1<m-k)) printf("1");
            n1++;
        }
        return 0;
    }
    printf("-1");
    return 0;
}