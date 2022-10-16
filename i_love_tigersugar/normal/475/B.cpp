#include<bits/stdc++.h>
#define MAX   222
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
char dirChar[]="^v<>";
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
char dirRow[MAX],dirCol[MAX];
bool vst[MAX][MAX];
int n,m;
void init(void) {
    scanf("%d%d",&m,&n);
    scanf("%s",dirRow+1);
    scanf("%s",dirCol+1);
}
inline bool inside(int x,int y) {
    if (x<1 || x>m || y<1 || y>n) return (false);
    return (true);
}
bool bfs(int sx,int sy) {
    queue<ii> q;
    memset(vst,false,sizeof vst);
    vst[sx][sy]=true;
    q.push(ii(sx,sy));
    while (!q.empty()) {
        ii u=q.front();q.pop();
        REP(i,4) if (inside(u.fi+dx[i],u.se+dy[i])) {
            ii v(u.fi+dx[i],u.se+dy[i]);
            if (dirRow[u.fi]==dirChar[i] || dirCol[u.se]==dirChar[i])
                if (!vst[v.fi][v.se]) {
                    vst[v.fi][v.se]=true;
                    q.push(v);
                }
        }
    }
    FOR(i,1,m) FOR(j,1,n) if (!vst[i][j]) return (false);
    return (true);
}
void process(void) {
    FOR(i,1,m) FOR(j,1,n) if (!bfs(i,j)) {
        printf("NO");
        return;
    }
    printf("YES");
}
int main(void) {
    init();
    process();
    return 0;
}