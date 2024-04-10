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
#define div   ___div
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
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
vector<int> adj[MAX];
int dis[MAX][MAX];
vector<int> haveDis[MAX][MAX];
int n,m;
double secondMove[MAX],secondMax[MAX];
bool used[MAX];
void loadGraph(void) {
    scanf("%d%d",&n,&m);
    memset(dis,0x3f,sizeof dis);
    FOR(i,1,n) dis[i][i]=0;
    REP(love,m) {
        int u,v; scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        minimize(dis[u][v],1);
        minimize(dis[v][u],1);
    }
}
void floyd(void) {
    FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) minimize(dis[i][j],dis[i][k]+dis[k][j]);
    FOR(i,1,n) FOR(j,1,n) haveDis[i][dis[i][j]].push_back(j);
}
double probWin(int x) {
    double res=0.0;
    REP(i,n) if (!haveDis[x][i].empty()) {
        double probHaveDis=1.0*haveDis[x][i].size()/n;
        double firstGuess=1.0/haveDis[x][i].size();
        double secondGuess=0.0;
        FOR(j,1,n) secondMove[j]=0;
        FORE(it,haveDis[x][i]) FORE(jt,adj[*it])
            secondMove[*jt]+=1.0/haveDis[x][i].size()*1.0/adj[*it].size();
//        printf("Start %d receive %d with prob %.9lf\n",x,i,probHaveDis);
//        FOR(j,1,n) printf("prob second of %d is %.9lf\n",j,secondMove[j]);
        FOR(y,1,n) {
            FOR(j,max(0,i-1),min(n-1,i+1)) FORE(it,haveDis[x][j])
                secondMax[dis[y][*it]]=0;
            FOR(j,max(0,i-1),min(n-1,i+1)) FORE(it,haveDis[x][j])
                maximize(secondMax[dis[y][*it]],secondMove[*it]);
            double sum=0;
            FOR(j,max(0,i-1),min(n-1,i+1)) FORE(it,haveDis[x][j]) {
                if (used[dis[y][*it]]) continue;
                used[dis[y][*it]]=true;
                sum+=secondMax[dis[y][*it]];
            }
            maximize(secondGuess,sum);
//            printf("Choose second %d is %.9lf\n",y,sum);
//            REP(j,n) printf("At dis %d has %d node with prob %.9lf\n",j,secondNode[j],secondDis[j]);
            FOR(j,max(0,i-1),min(n-1,i+1)) FORE(it,haveDis[x][j])
                used[dis[y][*it]]=false;
        }
        res+=probHaveDis*max(firstGuess,secondGuess);
    }
    return (res);
}
void process(void) {
    double res=0;
    FOR(i,1,n) maximize(res,probWin(i));
    printf("%.9lf\n",res);
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    loadGraph();
    floyd();
    process();
    return 0;
}