#include<cstdio>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
char a[MAX][MAX];
int n;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
inline bool inside(int x,int y) {
    if (x<1 || x>n || y<1 || y>n) return (false);
    return (a[x][y]=='o');
}
int main(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%s",a[i]+1);
    FOR(i,1,n) FOR(j,1,n) {
        int c=0;
        REP(d,4) if (inside(i+dx[d],j+dy[d])) c++;
        if (c%2) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}