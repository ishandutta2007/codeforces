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
#define built  __builtin_popcount
const int N=1e6+99;

int n,m,c,t,p[N],inc[N],res[2],adj[2][N],mark[N];
vector<int> g[N];

void dfs(int u){
    mark[u]=1;
    f(i,0,g[u].size())
        if(!mark[g[u][i]])
            dfs(g[u][i]);
    if(g[u].size()==0){
        if(p[u]==-1)
            p[u]=t++;
        adj[0][c]|=(1<<p[u]);
        adj[1][p[u]]|=(1<<c);
    }
}
int main(){
    fill(p,p+N,-1);
    cin>>n>>m;
    f(i,0,m){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        inc[v]++;
    }
    f(i,1,n+1)
        if(!inc[i]){
            fill(mark,mark+N,0);
            dfs(i);
            c++;
        }
    f(mask,1,(1<<t)-1){
        res[0]=0,res[1]=0;
        f(i,0,t)
            if(mask&(1<<i))
                res[0]|=adj[0][i],res[1]|=adj[1][i];
        if(built(res[0])<=built(mask) || built(res[1])<=built(mask))
            return cout<<"NO",0;
    }
    cout<<"YES";
}