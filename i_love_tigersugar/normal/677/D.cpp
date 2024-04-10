#include<bits/stdc++.h>
#define MAX   333
#define LIM   999
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
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
struct State {
    long long dis;
    int x,y;
    State() {
        x=y=dis=0;
    }
    State(int _x,int _y,long long _dis) {
        x=_x;y=_y;dis=_dis;
    }
    bool operator < (const State &s) const {
        return (dis>s.dis);
    }
};
long long f[MAX][MAX],dis[MAX][MAX];
vector<pair<int,int> > atLevel[MAX*MAX];
int a[MAX][MAX],m,n,p;
void init(void) {
    scanf("%d%d%d",&m,&n,&p);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
    FOR(i,1,m) FOR(j,1,n) atLevel[a[i][j]].push_back(make_pair(i,j));
}
bool inside(int x,int y) {
    if (x<1 || x>m || y<1 || y>n) return (false);
    return (true);
}
int Abs(int x) {
    return (x<0?-x:x);
}
int distan(int x,int y,int z,int t) {
    return (Abs(x-z)+Abs(y-t));
}
void smallUpdate(const vector<pair<int,int> > &prev,const vector<pair<int,int> > &next) {
    FORE(it,prev) FORE(jt,next)
        minimize(f[jt->fi][jt->se],f[it->fi][it->se]+distan(it->fi,it->se,jt->fi,jt->se));
}
void bigUpdate(const vector<pair<int,int> > &prev,const vector<pair<int,int> > &next) {
    priority_queue<State> q;
    memset(dis,0x3f,sizeof dis);
    FORE(it,prev) dis[it->fi][it->se]=f[it->fi][it->se];
    FORE(it,prev) q.push(State(it->fi,it->se,f[it->fi][it->se]));
    while (!q.empty()) {
        int x=q.top().x;
        int y=q.top().y;
        long long d=q.top().dis;
        q.pop();
        if (d!=dis[x][y]) continue;
        REP(i,4) if (inside(x+dx[i],y+dy[i])) {
            int vx=x+dx[i];
            int vy=y+dy[i];
            if (dis[vx][vy]>dis[x][y]+1) {
                dis[vx][vy]=dis[x][y]+1;
                q.push(State(vx,vy,dis[vx][vy]));
            }
        }
    }
    FORE(it,next) f[it->fi][it->se]=dis[it->fi][it->se];
}
void update(const vector<pair<int,int> > &prev,const vector<pair<int,int> > &next) {
    if (prev.size()>LIM && next.size()>LIM) bigUpdate(prev,next);
    else smallUpdate(prev,next);
}
void process(void) {
    memset(f,0x3f,sizeof f);
    FOR(i,1,m) FOR(j,1,n) if (a[i][j]==1) f[i][j]=distan(1,1,i,j);
    FOR(i,1,p-1) update(atLevel[i],atLevel[i+1]);
    FOR(i,1,m) FOR(j,1,n) if (a[i][j]==p) cout<<f[i][j]<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}