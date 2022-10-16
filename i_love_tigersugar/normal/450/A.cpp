#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int main(void) {
    int r=0;
    int t=0;
    int m,n;
    scanf("%d%d",&n,&m);
    REP(i,n) {
        int x;
        scanf("%d",&x);
        if (x/m+(x%m>0)>=r) {
            r=x/m+(x%m>0);
            t=i+1;
        }
    }
    printf("%d",t);
    return 0;
}