#include<bits/stdc++.h>
#define MAX   333
#define REP(i,n) for (int i=0;i<(n);i=i+1)
bool have[MAX];
int p,n;
int main(void) {
    scanf("%d%d",&p,&n);
    REP(i,n) {
        int t;
        scanf("%d",&t);
        if (have[t%p]) {
            printf("%d",i+1);
            return 0;
        }
        have[t%p]=true;
    }
    printf("-1");
    return 0;
}