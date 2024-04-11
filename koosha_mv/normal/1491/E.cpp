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
 
const int N=2e5+2;
 
int n,u,v,fib[30],sub[N];
vector<int> g[N];
 
void dfs(int x,int par,int k){
    sub[x]=1;
    f(i,0,g[x].size()) 
        if(g[x][i]!=par){
            dfs(g[x][i],x,k);
            sub[x]+=sub[g[x][i]];
        }
    if(sub[x]==fib[k]) u=x,v=par;
    if(sub[x]==fib[k+1]) v=x,u=par;
}
bool solve(int x,int k){
    //cout<<x<<" "<<k<<endl;
    if(k<2) return 1;
    u=0;
    dfs(x,0,k-2);
    if(u==0 || v==0){return 0; }
    int p=u,o=v;
    f(i,0,g[u].size())
        if(g[u][i]==v) 
            g[u].erase(g[u].begin()+i);
    f(i,0,g[v].size())
        if(g[v][i]==u) 
            g[v].erase(g[v].begin()+i);
    return (solve(p,k-2) && solve(o,k-1));
}
 
int main(){
    fib[0]=1,fib[1]=1;
    f(i,2,30){ fib[i]=fib[i-2]+fib[i-1]; }
    cin>>n;
    f(i,1,n){
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    f(i,0,30)
        if(n==fib[i] && solve(1,i))
            return cout<<"YES",0;
    cout<<"NO";
 }