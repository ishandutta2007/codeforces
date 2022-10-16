#include<bits/stdc++.h>
#define MAX   2020
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
const string noAnswer="Not unique";
const char ch[]="><v^";
const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};
bool vst[MAX][MAX];
char a[MAX][MAX];
char res[MAX][MAX];
int m,n;
void init(void) {
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",a[i]+1);
    FOR(i,1,m) FOR(j,1,n) res[i][j]=a[i][j];
}
bool inside(int x,int y) {
    if (x<1 || x>m || y<1 || y>n) return (false);
    return (true);
}
void putShape(const pair<int,int> &u,const pair<int,int> &v) {
    REP(i,4) if (u.fi+dx[i]==v.fi && u.se+dy[i]==v.se) res[u.fi][u.se]=ch[i];
    REP(i,4) if (v.fi+dx[i]==u.fi && v.se+dy[i]==u.se) res[v.fi][v.se]=ch[i];
    a[u.fi][u.se]=a[v.fi][v.se]='*';
}
int degree(int x,int y) {
    int res=0;
    REP(i,4) if (inside(x+dx[i],y+dy[i]) && a[x+dx[i]][y+dy[i]]=='.') res++;
    return (res);
}
void fixShape(void) {
    queue<pair<int,int> > q;
    FOR(i,1,m) FOR(j,1,n) if (inside(i,j) && a[i][j]=='.' && degree(i,j)==1) q.push(make_pair(i,j));
    while (!q.empty()) {
        int ux=q.front().fi;
        int uy=q.front().se;
        q.pop();
        if (a[ux][uy]!='.') continue;
        REP(i,4) {
            int vx=ux+dx[i];
            int vy=uy+dy[i];
            if (inside(vx,vy) && a[vx][vy]=='.') {
                putShape(make_pair(ux,uy),make_pair(vx,vy));
                REP(j,4) {
                    int tx=ux+dx[j];
                    int ty=uy+dy[j];
                    if (inside(tx,ty) && a[tx][ty]=='.' && degree(tx,ty)==1) q.push(make_pair(tx,ty));
                    tx=vx+dx[j];
                    ty=vy+dy[j];
                    if (inside(tx,ty) && a[tx][ty]=='.' && degree(tx,ty)==1) q.push(make_pair(tx,ty));
                }
                break;
            }
        }
    }
}
void process(void) {
    fixShape();
    FOR(i,1,m) FOR(j,1,n) if (a[i][j]=='.') {
        cout<<noAnswer<<endl;
        return;
    }
    FOR(i,1,m) {
        FOR(j,1,n) printf("%c",res[i][j]);
        printf("\n");
    }
}
int main(void) {
    init();
    process();
    return 0;
}