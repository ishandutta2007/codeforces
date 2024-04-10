#include<bits/stdc++.h>
#define MAX   444
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
struct State {
    int x,y,t;
    State() {
        x=y=t=0;
    }
    State(int _x,int _y,int _t) {
        x=_x;y=_y;t=_t;
    }
};
const int INF=(int)1e9+7;
bool adj[2][MAX][MAX];
int n,m;
int dis[MAX][MAX][2];
void init(void) {
    scanf("%d%d",&n,&m);
    REP(love,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[0][u][v]=adj[0][v][u]=true;
    }
    FOR(i,1,n) REP(j,2) adj[j][i][i]=true;
    FOR(i,1,n) FOR(j,1,n) if (i!=j) adj[1][i][j]=!adj[0][i][j];
}
void bfs(void) {
    memset(dis,0x3f,sizeof dis);
    queue<State> q;
    dis[1][1][0]=0;
    q.push(State(1,1,0));
    while (!q.empty()) {
        State u=q.front();q.pop();
        FOR(i,1,n) if ((!u.t && adj[0][u.x][i]) || (u.t && adj[1][u.y][i])) {
            State v(!u.t?i:u.x,u.t?i:u.y,u.t^1);
            if (v.x!=n && v.x==v.y && !v.t) continue;
            if (dis[v.x][v.y][v.t]>=INF) {
                dis[v.x][v.y][v.t]=dis[u.x][u.y][u.t]+1;
                q.push(v);
            }
        }
    }
    printf("%d\n",dis[n][n][0]>=INF?-1:dis[n][n][0]/2);
}
int main(void) {
    init();
    bfs();
    return 0;
}