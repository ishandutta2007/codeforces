#include<bits/stdc++.h>
#define MAX   111
#define REP(i,n) for (int i=0;i<(n);i=i+1)
char a[MAX][MAX];
int main(void) {
    int m,n;
    scanf("%d%d",&m,&n);
    REP(i,m) scanf("%s",a[i]);
    REP(i,m) REP(j,n) if (a[i][j]=='.') a[i][j]=(i+j)%2?'B':'W';
    REP(i,m) printf("%s\n",a[i]);
    return 0;
}