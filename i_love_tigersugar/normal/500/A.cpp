#include<cstdio>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
bool canGo[MAX];
int moveTo[MAX];
int n,goal;
int main(void) {
    canGo[1]=true;
    scanf("%d%d",&n,&goal);
    FOR(i,1,n-1) {
        scanf("%d",&moveTo[i]);
        if (canGo[i]) canGo[i+moveTo[i]]=true;
    }
    printf("%s\n",canGo[goal]?"YES":"NO");
    return 0;
}