#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
bool col[MAX][MAX];
int m,n,q;
bool checkSquare(int x,int y) {
    if (x<1 || y<1) return (false);
    if (x==m || y==n) return (false);
    REP(i,2) REP(j,2) if (!col[x+i][y+j]) return (false);
    return (true);
}
void process(void) {
    scanf("%d%d%d",&m,&n,&q);
    FOR(i,1,q) {
        int x,y;
        scanf("%d%d",&x,&y);
        col[x][y]=true;
        REP(j,2) REP(k,2) if (checkSquare(x-j,y-k)) {
            printf("%d\n",i);
            return;
        }
    }
    printf("0\n");
}
int main(void) {
    process();
    return 0;
}