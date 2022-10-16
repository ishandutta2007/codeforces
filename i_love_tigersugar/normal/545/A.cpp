#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
int a[MAX][MAX];
bool ok[MAX];
int n;
int main(void) {
    scanf("%d",&n);
    FOR(i,1,n) FOR(j,1,n) scanf("%d",&a[i][j]);
    FOR(i,1,n) ok[i]=true;
    FOR(i,1,n) FOR(j,1,n) {
        if (a[i][j]==1) ok[i]=false;
        if (a[i][j]==2) ok[j]=false;
        if (a[i][j]==3) ok[i]=ok[j]=false;
    }
    int cnt=0;
    FOR(i,1,n) if (ok[i]) cnt++;
    printf("%d\n",cnt);
    FOR(i,1,n) if (ok[i]) printf("%d ",i); printf("\n");
    return 0;
}