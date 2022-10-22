#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int t,n,m,c,c1,c2,p[N],q[N];
vector<int> adj[N];
set<int> g[N];

void solve(){
    cin>>n>>m;
    c=n,c1=1,c2=1;
    f(i,0,m){
        int u,v;
        Gett(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    f(i,1,n+1){
        int u=0;
        adj[i].pb(0);
        adj[i].pb(i);
        sort(adj[i].begin(),adj[i].end());
        if(adj[i].size()==n+1) p[i]=c,q[i]=c--;
        else{
            f(j,1,adj[i].size())
                if(adj[i][j]!=adj[i][j-1]+1)
                    u=adj[i][j]-1;
            if(adj[i][adj[i].size()-1]!=n) u=n;
            //cout<<i<<" "<<u<<endl;
            g[i].insert(u);
            g[u].insert(i);
        }
    }
    f(i,1,n+1){
        vector<int> v;
        while(g[i].size()){
            int u=*g[i].begin();
            g[i].erase(u);
            g[u].erase(i);
            if(g[u].size()==0 || (g[i].size()==0 && v.size()==0))
                v.pb(u);
        }
        f(j,0,v.size())
            g[i].insert(v[j]),g[v[j]].insert(i);
    }
    f(i,1,n+1){
        if(1<g[i].size() || (g[i].size() && i<(*g[i].begin()) && g[(*g[i].begin())].size()==1)){
            p[i]=c1++;
            for(auto u:g[i])
                p[u]=c1++,q[u]=c2++;
            q[i]=c2++;
        }
    }
    f(i,1,n+1) cout<<p[i]<<" "; cout<<endl;
    f(i,1,n+1) cout<<q[i]<<" "; cout<<endl;
    f(i,1,n+1)
        g[i].clear(),adj[i].clear();
}

int main(){
    cin>>t;
    while(t--)
        solve();
}