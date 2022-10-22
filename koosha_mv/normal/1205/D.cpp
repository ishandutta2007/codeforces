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
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1005;

int n,mv,cntrd,sub[N],val[N],mark[N],Par[N];
vector<int> v[2],g[N];

void dfs(int x,int par){
    sub[x]=1;
    f(i,0,g[x].size())
        if(g[x][i]!=par){
            dfs(g[x][i],x);
            Par[g[x][i]]=x;
            sub[x]+=sub[g[x][i]];
        }
    if((n+1)/2<=sub[x] && !cntrd) cntrd=x; 
}
void DFS(int x,int s){
    mark[x]=1;
    v[s].pb(x);
    f(i,0,g[x].size())
        if(!mark[g[x][i]])
            DFS(g[x][i],s);
}
void set_value(){
    if(sz(v[1])<sz(v[0])) swap(v[0],v[1]);
    int x=sz(v[0])+1;
    f(i,0,sz(v[0]))
        val[v[0][i]]=i+1;
    f(i,0,sz(v[1]))
        val[v[1][i]]=(i+1)*x;
}

int main(){
    cin>>n;
    if(n==1) return 0;
    f(i,1,n){
        int u,v;
        Gett(u,v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);
    dfs(cntrd,0);
    mark[cntrd]=1;

    f(i,0,sz(g[cntrd]))
        if(!mv && (n+2)/3<=sub[g[cntrd][i]]){
            DFS(g[cntrd][i],0);
            mv=1;
        }
    if(!mv){
        for(int i=0;sz(v[0])<(n+2)/3;i++)
            DFS(g[cntrd][i],0);
    }
    f(i,0,sz(g[cntrd]))
        if(!mark[g[cntrd][i]])
            DFS(g[cntrd][i],1);
    
    set_value();
    f(i,1,n+1)
        if(i!=cntrd)
            cout<<i<<" "<<Par[i]<<" "<<val[i]-val[Par[i]]<<'\n';
}