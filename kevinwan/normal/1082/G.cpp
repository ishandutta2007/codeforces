#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=2e3+10;
const ll mod=1e9+7;
template<typename T>
struct dinic{
    int n;
    T inf;
    struct E{
        int to,rev;
        T cap;
    };
    vector<vector<E>>g;
    vector<int>at,dep;
    dinic(int n,T inf=LLONG_MAX){
        this->n=n;
        this->inf=inf;
        g.resize(n);
        at.resize(n);
        dep.resize(n);
    }
    void addEdge(int x,int y,T c){
        g[x].push_back({y,g[y].size(),c});
        g[y].push_back({x,g[x].size()-1,0});
    }
    int s,t;
    bool bfs(){
        queue<int>q;
        q.push(s);
        fill(dep.begin(),dep.end(),-1);
        dep[s]=0;
        while(q.size()){
            int x=q.front();
            q.pop();
            for(E e:g[x])if(dep[e.to]==-1&&e.cap>0){
                dep[e.to]=dep[x]+1;
                q.push(e.to);
            }
        }
        return dep[t]!=-1;
    }
    T dfs(int x,T cap){
        if(x==t)return cap;
        for(;at[x]<g[x].size();at[x]++){
            E e=g[x][at[x]];
            if(e.cap<=0||dep[e.to]!=dep[x]+1)continue;
            T v=dfs(e.to,min(cap,e.cap));
            if(v){
                g[x][at[x]].cap-=v;
                g[e.to][e.rev].cap+=v;
                return v;
            }
        }
        return 0;
    }
    T maxflow(int s,int t){
        this->s=s,this->t=t;
        T ans=0;
        while(bfs()){
            fill(at.begin(),at.end(),0);
            T v;
            do{
                ans+=(v=dfs(s,inf));
            }while(v>0);
        }
        return ans;
    }
};
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    dinic<ll> D(n+m+2);
    for(int i=1;i<=n;i++){
        ll x;
        scanf("%lld",&x);
        D.addEdge(0,i,x);
    }
    ll ans=0;
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        D.addEdge(a,n+i,0x3f3f3f3f3f3f3f3f);
        D.addEdge(b,n+i,0x3f3f3f3f3f3f3f3f);
        D.addEdge(n+i,n+m+1,c);
        ans+=c;
    }
    ans-=D.maxflow(0,n+m+1);
    printf("%lld",ans);
}