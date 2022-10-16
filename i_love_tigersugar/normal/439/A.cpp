#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int main(void) {
    int n,s,d;
    s=0;
    scanf("%d%d",&n,&d);
    REP(zz,n) {
        int v;
        scanf("%d",&v);
        s+=v;
    }
    if (s+(n-1)*10>d) printf("-1");
    else printf("%d",(d-s)/5);
    return 0;
}