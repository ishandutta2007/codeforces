#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define REP(i,m) for(int i=0;i<m;++i)
#define mp make_pair
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define fr first
#define sc second
#define dupi(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
typedef long long int lint;
typedef pair<lint,lint> pi;
int n,m,k;
vector<pi> g[100005];
int mark[100005],belong[100005];
lint cost[100005];
pair<lint,pi> es[200005];
struct uf{
    int par[100005];
    uf(){
        memset(par,-1,sizeof(par));
    }
    int root(int a){
        if(par[a]==-1) return a;
        return par[a]=root(par[a]);
    }
    void unite(int a,int b){
        a=root(a);b=root(b);
        if(a==b) return ;
        par[a]=b;
    }
};
uf u;
int main(){
    scanf("%d%d",&n,&m);
    REP(i,m){
        lint a,b,c;cin>>a>>b>>c;--a;--b;
        g[a].pb(pi(b,c));
        g[b].pb(pi(a,c));
    }
    priority_queue<pi,vector<pi>,greater<pi > >pq;
    scanf("%d",&k);
    REP(i,n) cost[i]=1e18;
    REP(i,k){
        int a;scanf("%d",&a);--a;
        mark[a]=1;
        cost[a]=0;
        pq.push(pi(0,a));
        belong[a]=a;
    }
    lint res=0;
    while(!pq.empty()){
        pi cur=pq.top();pq.pop();
        if(cost[cur.sc]!=cur.fr) continue;
        REP(i,g[cur.sc].size()){
            pi& e=g[cur.sc][i];
            if(cost[e.fr]<=cur.fr+e.sc) continue;
            cost[e.fr]=cur.fr+e.sc;
            belong[e.fr]=belong[cur.sc];
            pq.push(pi(cost[e.fr],e.fr));
        }
    }
    int cnt=0;
    REP(i,n) REP(j,g[i].size()){
        int to=g[i][j].fr;
        int px=belong[i],py=belong[to];
        if(px!=py) es[cnt++]=mp(cost[i]+cost[to]+g[i][j].sc,mp(px,py));
    }
    sort(es,es+cnt);
    REP(i,cnt) if(u.root(es[i].sc.fr)!=u.root(es[i].sc.sc)){
        u.unite(es[i].sc.fr,es[i].sc.sc);
        res+=es[i].fr;
    }
    REP(i,n) cost[i]=1e18;
    pq.push(pi(0,0));
    cost[0]=0;
    while(!pq.empty()){
        pi cur=pq.top();pq.pop();
        if(cost[cur.sc]!=cur.fr) continue;
        if(mark[cur.sc]) break;
        REP(i,g[cur.sc].size()){
            pi& e=g[cur.sc][i];
            if(cost[e.fr]<=cur.fr+e.sc) continue;
            cost[e.fr]=cur.fr+e.sc;
            pq.push(pi(cost[e.fr],e.fr));
        }
    }
    lint mindif=1e18;
    REP(i,n) if(mark[i]) mindif=min(mindif,cost[i]);
    cout<<res+mindif<<endl;
    
    return 0;
}