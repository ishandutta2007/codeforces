#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int main(void) {
    int n,s;
    scanf("%d%d",&n,&s);
    int m=-1;
    REP(zz,n) {
        int v;
        scanf("%d",&v);
        if (m<v) m=v;
        s-=v;
    }
    if (s+m>=0) printf("YES"); else printf("NO");
    return 0;
}