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

const int N=5e5+99,Lg=20,inf=1e9;

int n,mn=inf,rt,a[N],Par[Lg][N];
vector<int> g[N];
ll ans;

void dfs(int x,int par){
    ll res=1ll*inf*inf;
    Par[0][x]=par;
    f(lg,1,Lg)
        Par[lg][x]=Par[lg-1][Par[lg-1][x]];
    f(lg,0,Lg)
        minm(res,1ll*a[Par[lg][x]]*(lg+1));
    if(x!=rt) ans+=res+a[x];
    
    f(i,0,g[x].size())
        if(g[x][i]!=par)
            dfs(g[x][i],x);
}

int main(){
    cin>>n;
    f(i,1,n+1){
        gett(a[i]);
        if(a[i]<mn)
            mn=a[i],rt=i;
    }
    f(i,1,n){
        int u,v;
        Gett(u,v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(rt,rt);
    cout<<ans;
}