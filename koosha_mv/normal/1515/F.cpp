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
 
const int N=1e6+99;
 
int n,m,deg[N],x,mark[N],par[N],ans[N],s,t;
ll sum,a[N];
queue<int> q;
map<pair<int,int> ,int > edge;
vector<int> g[N];
 
void dfs1(int x){
    mark[x]=1;
    f(i,0,g[x].size())
        if(!mark[g[x][i]]){
            dfs1(g[x][i]);
            par[g[x][i]]=x;
        }
    q.push(x);
}
int main(){
	cin>>n>>m>>x;
	f(i,1,n+1){ cin>>a[i]; sum+=a[i]; }
	if(sum<1ll*(n-1)*x) return cout<<"NO",0;
	f(i,0,m){
	    int u,v;
	    Gett(u,v);
	    g[u].pb(v);
	    g[v].pb(u);
	    edge[mp(u,v)]=i+1;
	    edge[mp(v,u)]=i+1;
	}
	dfs1(1);
	t=n-2;
	while(1){
	    int u=q.front();
	    q.pop();
	    if(u==1) break;
	    if(a[u]+a[par[u]]>=x){
	        ans[s++]=edge[mp(u,par[u])];
	        a[par[u]]+=a[u]-x;
	    }
	    else{
	        ans[t--]=edge[mp(u,par[u])];
	    }
	}
	cout<<"YES"<<endl;
	f(i,0,n-1) cout<<ans[i]<<" ";
}