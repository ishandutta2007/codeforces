#include<bits/stdc++.h>
#define MAX   555
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
const char yes[]="YES";
const char no[]="NO";
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
char a[MAX][MAX];
int m,n,sx,sy,ex,ey;
bool vst[MAX][MAX];
void init(void) {
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",a[i]+1);
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
}
bool inside(int x,int y) {
    if (x<1 || x>m || y<1 || y>n) return (false);
    return (true);
}
bool bfs(void) {
    queue<pair<int,int> > q;
    vst[sx][sy]=true;
    q.push(make_pair(sx,sy));
    while (!q.empty()) {
        int ux=q.front().fi;
        int uy=q.front().se;
        q.pop();
        if (ux==ex && uy==ey) return (true);
        REP(i,4) if (inside(ux+dx[i],uy+dy[i])) {
            int vx=ux+dx[i];
            int vy=uy+dy[i];
            if (vx==ex && vy==ey) return (true);
            if (a[vx][vy]=='.' && !vst[vx][vy]) {
                vst[vx][vy]=true;
                q.push(make_pair(vx,vy));
            }
        }
    }
    return (false);
}
int countNear(int x,int y) {
    int res=0;
    REP(i,4) if (inside(x+dx[i],y+dy[i]) && a[x+dx[i]][y+dy[i]]=='.') res++;
    return (res);
}
bool process(void) {
    if (sx==ex && sy==ey) return (countNear(sx,sy)>0);
    if (!bfs()) return (false);
    REP(i,4) if (sx+dx[i]==ex && sy+dy[i]==ey) {
        if (a[ex][ey]=='.') return (countNear(ex,ey)>0);
        return (true);
    }
    if (a[ex][ey]=='.') return (countNear(ex,ey)>1);
    return (true);
}
int main(void) {
    init();
    printf("%s\n",process()?yes:no);
    return 0;
}