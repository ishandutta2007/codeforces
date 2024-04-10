#include<bits/stdc++.h>
#define MAX   444
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
char a[MAX][MAX];
int c[MAX][MAX][4];
int dx[]={1,1,1,0};
int dy[]={-1,0,1,1};
int m,n,res;
void init(void) {
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",a[i]+1);
    FOR(i,1,m) FOR(j,1,n) a[i][j]-=48;
    FOR(i,1,m) FOR(j,1,n) REP(k,4) c[i][j][k]=c[i-dx[k]][j-dy[k]][k]+a[i][j];
}
inline bool inside(int x,int y) {
    if (x<1) return (false);
    if (y<1) return (false);
    if (x>m) return (false);
    if (y>n) return (false);
    return (a[x][y]==0);
}
inline bool ok(int x,int y,int d,int k) {
    if (!inside(x,y)) return (false);
    if (!inside(x+dx[d]*k,y+dy[d]*k)) return (false);
    return (c[x+dx[d]*k][y+dy[d]*k][d]==c[x-dx[d]][y-dy[d]][d]);
}
void process(void) {
    FOR(x,1,m) FOR(y,1,n) if (a[x][y]==0)
        REP(d,4) FOR(k,1,m+n) {
            if (!inside(x+dx[d]*k,y+dy[d]*k)) break;
            if (d==0) {
                if (ok(x,y-k,3,k) && ok(x,y-k,1,k)) res++;
                if (ok(x,y,1,k) && ok(x+k,y-k,3,k)) res++;
            }
            if (d==2) {
                if (ok(x,y,1,k) && ok(x+k,y,3,k)) res++;
                if (ok(x,y,3,k) && ok(x,y+k,1,k)) res++;
            }
            if (k%2==1) continue;
            if (d==1) {
                if (ok(x,y,0,k/2) && ok(x+k/2,y-k/2,2,k/2)) res++;
                if (ok(x,y,2,k/2) && ok(x+k/2,y+k/2,0,k/2)) res++;
            }
            if (d==3) {
                if (ok(x-k/2,y+k/2,0,k/2) && ok(x-k/2,y+k/2,2,k/2)) res++;
                if (ok(x,y,2,k/2) && ok(x,y+k,0,k/2)) res++;
            }
        }
    printf("%d",res);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    process();
    return 0;
}