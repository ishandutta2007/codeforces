#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define is_bit(x,y) (0<(x&(1ll<<y)))
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6+99;

int n,t,da,db,a,b,fa;
vector<int> g[N];
pair<int,int> mx;

void dfs(int x,int par,int dist){
    if(x==b) fa=dist;
    if(mx<mp(dist,x)) mx=mp(dist,x);
    f(i,0,g[x].size())
        if(g[x][i]!=par)
            dfs(g[x][i],x,dist+1);
}
string solve(){
    fa=0;
    if(db<da*2+1) return "Alice";   
    mx=mp(0,0);    
    dfs(1,0,0);
    dfs(mx.S,0,0);
    dfs(a,0,0);
    if((mx.F+1)/2<=da || fa<=da) return "Alice";
    return "Bob";
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>a>>b>>da>>db;
        f(i,1,n+1) g[i].clear();
        f(i,1,n){
            int u,v;
            Gett(u,v);
            g[u].pb(v);
            g[v].pb(u);
        }
        cout<<solve()<<'\n';
    }
}