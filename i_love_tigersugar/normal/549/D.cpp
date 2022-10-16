#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
long long cur[MAX][MAX];
long long goal[MAX][MAX];
int m,n,res;
char a[MAX][MAX];
void init(void) {
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",a[i]+1);
    FOR(i,1,m) FOR(j,1,n) goal[i][j]=a[i][j]=='W'?1:-1;
}
void change(int x,int y,long long v) {
    res++;
    FOR(i,1,x) FOR(j,1,y) cur[i][j]+=v;
}
void process(void) {
    FORD(i,m,1) FORD(j,n,1) if (goal[i][j]!=cur[i][j]) change(i,j,goal[i][j]-cur[i][j]);
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}