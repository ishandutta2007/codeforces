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
#define gett(x) scanf("%d",&x);a
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

const int N=2e5+9,M=7;
 
int n,t,a[N],mark[N];
vector<int> v[N],g[N];
ll ans[N];

void dfs(int x){
    t++;
    mark[x]=0;
    f(i,0,g[x].size())
        if(mark[g[x][i]])
            dfs(g[x][i]);
}
void solve(int x){
    f(i,0,sz(v[x]))
        mark[v[x][i]]=1;
    f(i,0,sz(v[x]))
        if(mark[v[x][i]]==1){
            t=0;
            dfs(v[x][i]);
            ans[x]+=1ll*t*(t+1)/2;
        }
    f(i,0,sz(v[x]))
        mark[v[x][i]]=0;    
}
     
int main(){
    cin>>n;
    f(i,1,n+1){ 
        gett(a[i]);
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0){
                v[j].pb(i);
                if(j*j!=a[i])
                    v[a[i]/j].pb(i);
            }
        }
    }
    f(i,1,n){
        int u,v;
        Gett(u,v);
        g[u].pb(v);
        g[v].pb(u);
    }
    f(i,1,N)
        solve(i);
    f_(i,N-1,1)
        for(int j=i*2;j<N;j+=i)
            ans[i]-=ans[j];
    f(i,1,N)
        if(ans[i])
            cout<<i<<" "<<ans[i]<<'\n';
}