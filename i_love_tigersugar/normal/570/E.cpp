#include<bits/stdc++.h>
#define MAX   505
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int mod=(int)1e9+7;
int m,n;
char a[MAX][MAX];
int f[2][MAX][MAX];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
void init(void) {
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",a[i]+1);
}
bool inside(int x,int y) {
    if (x<1 || x>m || y<1 || y>n) return (false);
    return (true);
}
void add(int &x,const int &y) {
    x+=y;
    if (x>=mod) x-=mod;
}
void process(void) {
    if ((m+n)%2==0) {
        FOR(x,1,(m+n)/2+1) {
            int y=(m+n)/2+1-x;
            if (inside(x,y)) add(f[(x+y)&1][x][x],1);
        }
    } else {
        FOR(x,1,(m+n)/2+1) FOR(u,1,(m+n+2)-((m+n)/2+1)) {
            int y=(m+n)/2+1-x;
            int v=(m+n+2)-((m+n)/2+1)-u;
            if (inside(x,y) && inside(u,v) && a[x][y]==a[u][v])
                FOR(i,2,3) if (x+dx[i]==u && y+dy[i]==v)
                    add(f[(x+y)&1][x][u],1);
        }
    }
    FORD(xy,(m+n)/2+1,3) {
        int cur=xy&1;
        //int next=cur^1;
        FOR(x,1,xy) FOR(u,1,(m+n+2)-xy) {
            int y=xy-x;
            int v=(m+n+2)-xy-u;
            if (!inside(x,y) || !inside(u,v)) continue;
            if (f[cur][x][u]>0) {
                //printf("F %d %d %d %d = %d\n",x,y,u,v,f[cur][x][u]);
                FOR(i,0,1) FOR(j,2,3) {
                    int tx=x+dx[i];
                    int ty=y+dy[i];
                    int tu=u+dx[j];
                    int tv=v+dy[j];
                    if (inside(tx,ty) && inside(tu,tv) && a[tx][ty]==a[tu][tv])
                        add(f[(tx+ty)&1][tx][tu],f[cur][x][u]);
                }
                f[cur][x][u]=0;
            }
        }
    }
    printf("%d\n",f[0][1][m]);
}
int main(void) {
    init();
    process();
    return 0;
}