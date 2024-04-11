#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define Add(x,y) x=Mod(x+y);
#define mp make_pair
#define ll long long
#define pb push_back
#define F first
#define S second

const int N=1e4+9;
const ll inf=1e17;


int n,m,k,s1,s2,t,Draw,Win,c[N];
ll dist[N];
pair<int, pair<int,int> > par[N];
vector<pair<pair<int,int>, int> > fixedge;
vector<pair<int,pair<int,int> > > g[N],G[N];
pair<pair<int,int> ,pair<int,int> > e,Edge[N];
map<pair<pair<int,int>, pair<int,int> >, int > ans;
vector<pair<pair<int,int>, pair<int,int> > > edge;
map<pair<pair<int,int>, pair<int,int> >, bool > mark;

void output(){
    if(dist[s1]<dist[s2]) cout<<"WIN";
    if(dist[s1]==dist[s2]) cout<<"DRAW";
    if(dist[s2]<dist[s1]) cout<<"LOSE";
    cout<<'\n';
    if(dist[s1]<=dist[s2])
        f(i,0,k)
            cout<<(mark[Edge[i]] ? Edge[i].S.F : Edge[i].S.S)<<" ";
    exit(0);
}
void make_graph(){
    f(i,1,n+1) g[i].clear();
    f(i,0,edge.size()){
        int u=edge[i].F.F,v=edge[i].F.S,l=edge[i].S.F,r=edge[i].S.S;
        if(mark[edge[i]])
            g[v].pb(mp(u,mp(l,r)));
        else
            g[v].pb(mp(u,mp(r,l)));
    }
    f(i,0,fixedge.size()){
        int u=fixedge[i].F.F,v=fixedge[i].F.S,w=fixedge[i].S;
        g[v].pb(mp(u,mp(w,0)));
    }
}
void dfs1(int x,pair<pair<int,int>, pair<int,int> > p){
    c[x]=0;
    if(x==s1) c[x]=1;
    f(i,0,G[x].size()){
        dfs1(G[x][i].F,mp(mp(G[x][i].F,x),G[x][i].S));
        c[x]|=c[G[x][i].F];
    }
    if(c[x] && p.S.S)
        mark[p]=1;
}
void dfs2(int x,pair<pair<int,int>, pair<int,int> > p){
    c[x]=0;
    if(x==s1) c[x]=1;
    if(x==s2) c[x]=2;
    f(i,0,G[x].size()){
        dfs2(G[x][i].F,mp(mp(G[x][i].F,x),G[x][i].S));
        c[x]|=c[G[x][i].F];
    }
    if(c[x]==3 && p.S.S && e.S.S==0)
        e=p;
}
void reset_mark(int s){
    mark.clear();
    f(i,0,edge.size())  
        mark[edge[i]]=s;
}
void dijkstra_tree(){
    f(i,1,n+1) G[i].clear();
    set<pair<ll,int> > s;
    fill(dist,dist+N,inf);
    dist[t]=0;
    f(i,1,n+1)
        s.insert(mp(dist[i],i));
    while(s.size()){
        int u=(*s.begin()).S;
        s.erase(*s.begin());
        if(dist[u]==inf) return ;
        if(u!=t) G[par[u].F].pb(mp(u, par[u].S));
        f(i,0,g[u].size()){
            int v=g[u][i].F;
            if(dist[u]+g[u][i].S.F<dist[v]){
                s.erase(mp(dist[v], v));
                dist[v]=dist[u]+g[u][i].S.F;
                s.insert(mp(dist[v], v));
                par[v]=mp(u,mp(g[u][i].S.F, g[u][i].S.S));
            }
        }
    }
}

void do_it(){
    e=mp(mp(0,0),mp(0,0));
    reset_mark(1);
    make_graph();
    dijkstra_tree();
    reset_mark(0);
    dfs1(t,mp(mp(0,0),mp(0,0)));
    make_graph();
    dijkstra_tree();
    dfs2(t,mp(mp(0,0),mp(0,0)));
    if(e.S.S==0 || dist[s1]<dist[s2]) output();
    f(i,0,edge.size())
        if(edge[i]==e){
            edge.erase(edge.begin()+i);
            fixedge.pb(mp(mp(e.F.F,e.F.S),e.S.S));
            break;
        }
}

int main(){
    cin>>n>>m>>k;
    cin>>s1>>s2>>t;
    f(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        if(u!=v)
            fixedge.pb(mp(mp(u,v),w));
    }
    f(i,0,k){
        int u,v,l,r;
        cin>>u>>v>>l>>r;
        if(u!=v)
        	edge.pb(mp(mp(u,v),mp(l,r)));
        Edge[i]=(mp(mp(u,v),mp(l,r)));
    }
    f(i,0,k+1)
        do_it();
}