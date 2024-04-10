#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=2e5+10;
map<int,int>g[mn];
bool cyc;
set<int>rem;
int n,m;
int vis[mn];
struct dsu{
    int p[mn];
    int f(int x){return (x==p[x])?x:(p[x]=f(p[x]));}
    void u(int a,int b){p[f(a)]=f(b);}
    dsu(){iota(p,p+mn,0);}
};
dsu ds,sds;
void dfs(int x,int p){
    vis[x]=1;
    for(int i=*rem.begin();i<=n;i=*rem.upper_bound(i)){
        if(i==x||i==p||g[x].count(i))continue;
        if(vis[i]){
            cyc=1;
            rem.erase(i);
            continue;
        }
        dfs(i,x);
        ds.u(i,x);
    }
}
struct edge{
    int a,b,c;
};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    vector<edge> ve;
    cin>>n>>m;
    int www=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=c;
        www^=c;
        ve.push_back({a,b,c});
    }
    for(int i=1;i<=n+1;i++)rem.insert(i);
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i,-1);
    sort(ve.begin(),ve.end(),[](auto a,auto b){return a.c<b.c;});
    ll ans=0;
    if(!cyc)ans=www;
    for(edge e:ve){
        if(ds.f(e.a)!=ds.f(e.b)){
            ans+=e.c;
            ds.u(e.a,e.b);
            sds.u(e.a,e.b);
        }
        else if(!cyc){
            if(sds.f(e.a)!=sds.f(e.b)){
                ans+=min(0,e.c-www);
                cyc=1;
            }
        }
    }
    printf("%lld\n",ans);
}