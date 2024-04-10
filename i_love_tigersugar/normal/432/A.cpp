#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int main(void) {
    int n,k,c=0;
    scanf("%d%d",&n,&k);
    REP(zz,n) {
        int v;
        scanf("%d",&v);
        if (v<=5-k) c++;
    }
    printf("%d",c/3);
    return 0;
}