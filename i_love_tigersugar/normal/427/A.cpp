#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int main(void) {
    int n;
    scanf("%d",&n);
    int rem=0;
    int res=0;
    REP(zz,n) {
        int v;
        scanf("%d",&v);
        if (v<0) {
            if (rem<=0) res++; else rem--;
        }
        else rem+=v;
    }
    printf("%d",res);
    return 0;
}