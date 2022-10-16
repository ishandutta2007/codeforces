#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
int d[13][13];
int sx,sy,tx,ty;
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
bool inside(int x,int y) {
    return (0<x && x<9 && 0<y && y<9);
}
void init(void) {
    scanf("%d",&sx);
    scanf("%d",&sy);
    scanf("%d",&tx);
    scanf("%d",&ty);
}
void bfs_nonking(int mod) {
    queue<ii> q;
    while (!q.empty()) q.pop();
    memset(d,-1,sizeof d);
    q.push(ii(sx,sy));
    d[sx][sy]=0;
    while (!q.empty()) {
        int ux=q.front().fi;
        int uy=q.front().se;
        q.pop();
        if (ux==tx && uy==ty) {
            printf("%d ",d[ux][uy]);
            return;
        }
        REP(i,8) if (i%2==mod) FOR(j,1,10)
            if (inside(ux+dx[i]*j,uy+dy[i]*j)) {
                int vx=ux+dx[i]*j;
                int vy=uy+dy[i]*j;
                if (d[vx][vy]<0) {
                    d[vx][vy]=d[ux][uy]+1;
                    q.push(ii(vx,vy));
                }
            }
    }
    printf("0 ");
}
void bfs_king(void) {
    queue<ii> q;
    while (!q.empty()) q.pop();
    memset(d,-1,sizeof d);
    q.push(ii(sx,sy));
    d[sx][sy]=0;
    while (!q.empty()) {
        int ux=q.front().fi;
        int uy=q.front().se;
        q.pop();
        if (ux==tx && uy==ty) {
            printf("%d",d[ux][uy]);
            return;
        }
        REP(i,8) if (inside(ux+dx[i],uy+dy[i])) {
            int vx=ux+dx[i];
            int vy=uy+dy[i];
            if (d[vx][vy]<0) {
                d[vx][vy]=d[ux][uy]+1;
                q.push(ii(vx,vy));
            }
        }
    }
}
int main(void) {
    init();
    REP(i,2) bfs_nonking(1-i);
    bfs_king();
    return 0;
}