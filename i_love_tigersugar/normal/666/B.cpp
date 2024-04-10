#include<bits/stdc++.h>
#define MAX   3030
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
vector<int> adj[MAX];
int dis[MAX][MAX];
int maxFrom[MAX][5],maxTo[MAX][5];
int n,m;
void loadGraph(void) {
    scanf("%d%d",&n,&m);
    REP(love,m) {
        int u,v; scanf("%d%d",&u,&v);
        adj[u].push_back(v);
    }
}
void bfs(int s) {
    queue<int> q;
    dis[s][s]=0;
    q.push(s);
    while (!q.empty()) {
        int u=q.front();q.pop();
        FORE(it,adj[u]) if (dis[s][*it]<0) {
            dis[s][*it]=dis[s][u]+1;
            q.push(*it);
        }
    }
}
bool distinct(int a,int b,int c,int d) {
    if (a==b || a==c || a==d || b==c || b==d || c==d) return (false);
    return (true);
}
void process(void) {
    memset(dis,-1,sizeof dis);
    FOR(i,1,n) bfs(i);
    memset(maxFrom,-1,sizeof maxFrom);
    memset(maxTo,-1,sizeof maxTo);
    FOR(i,1,n) {
        vector<pair<int,int> > v;
        FOR(j,1,n) if (j!=i && dis[i][j]>=0) v.push_back(make_pair(dis[i][j],j));
        sort(ALL(v),greater<pair<int,int> > ());
        REP(j,min(5,(int)v.size())) maxFrom[i][j]=v[j].se;
        v.clear();
        FOR(j,1,n) if (j!=i && dis[j][i]>=0) v.push_back(make_pair(dis[j][i],j));
        sort(ALL(v),greater<pair<int,int> > ());
        REP(j,min(5,(int)v.size())) maxTo[i][j]=v[j].se;
    }
    int a,b,c,d;
    a=b=c=d=-1;
    FOR(i,1,n) FOR(j,1,n) if (i!=j && dis[i][j]>0) {
        REP(x,5) REP(y,5) {
            int k=maxTo[i][x];
            int l=maxFrom[j][y];
            if (k>0 && l>0 && distinct(i,j,k,l))
                if (a<0 || dis[k][i]+dis[i][j]+dis[j][l]>dis[a][b]+dis[b][c]+dis[c][d]) {
                    a=k;b=i;c=j;d=l;
                }
        }
    }
    printf("%d %d %d %d\n",a,b,c,d);
}
int main(void) {
    loadGraph();
    process();
    return 0;
}