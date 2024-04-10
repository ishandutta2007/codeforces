#include<bits/stdc++.h>
#define MAX   1010
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
const int INF=(int)1e9+7;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
char a[MAX][MAX];
int dis[5][MAX][MAX];
int compDis[5][5];
int m,n;
void init(void) {
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",a[i]+1);
}
bool inside(int x,int y) {
    if (x<1 || x>m || y<1 || y>n) return (false);
    return (true);
}
void bfs(int type) {
    queue<pair<int,int> > q;
    FOR(i,1,m) FOR(j,1,n) if (a[i][j]==type+'0') {
        dis[type][i][j]=0;
        q.push(make_pair(i,j));
    }
    while (!q.empty()) {
        int ux=q.front().fi;
        int uy=q.front().se;
        q.pop();
        REP(i,4) if (inside(ux+dx[i],uy+dy[i])) {
            int vx=ux+dx[i];
            int vy=uy+dy[i];
            if (a[vx][vy]!='#' && dis[type][vx][vy]>=INF) {
                dis[type][vx][vy]=dis[type][ux][uy]+1;
                q.push(make_pair(vx,vy));
            }
        }
    }
}
void answer(int x) {
    if (x>m*n) x=-1;
    printf("%d\n",x);
    exit(0);
}
void process(void) {
    memset(dis,0x3f,sizeof dis);
    memset(compDis,0x3f,sizeof compDis);
    FOR(k,1,3) bfs(k);
    FOR(i,1,m) FOR(j,1,n) if ('1'<=a[i][j] && a[i][j]<='3')
        FOR(k,1,3) minimize(compDis[a[i][j]-'0'][k],dis[k][i][j]);
    int path12=compDis[1][2]<=1;
    int path23=compDis[2][3]<=1;
    int path31=compDis[3][1]<=1;
    if (path12+path23+path31>=2) answer(0);
    if (path12) answer(min(compDis[2][3],compDis[3][1])-1);
    if (path23) answer(min(compDis[3][1],compDis[1][2])-1);
    if (path31) answer(min(compDis[1][2],compDis[2][3])-1);
    int res=INF;
    minimize(res,compDis[1][2]+compDis[1][3]-2);
    minimize(res,compDis[2][1]+compDis[2][3]-2);
    minimize(res,compDis[3][1]+compDis[3][2]-2);
    FOR(i,1,m) FOR(j,1,n) if (a[i][j]=='.')
        minimize(res,0LL+dis[1][i][j]+dis[2][i][j]+dis[3][i][j]-2);
    answer(res);
}
int main(void) {
    init();
    process();
    return 0;
}