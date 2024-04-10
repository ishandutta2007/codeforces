#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int main(void) {
    int n,x,s;
    s=0;
    scanf("%d%d",&n,&x);
    REP(i,n) {
        int v;
        scanf("%d",&v);
        s+=v;
    }
    if (s<0) s=-s;
    printf("%d",s/x+(s%x>0));
}