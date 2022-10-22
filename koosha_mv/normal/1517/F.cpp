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

const int N=305,mod=998244353;

int n,ans,dp[N][N][N][2],pd[N][N][2][2],sum[N][N][2],res[N];
vector<int> g[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

void dfs(int x,int par){
    vector<int> v(2);
    f(i,0,n)
        f(j,0,n)
            if(i<=j)
                dp[x][i][j][(i==0)]=1;
    f(p,0,g[x].size()){
        int u=g[x][p];
        if(u!=par){
            dfs(u,x);
            f(i,0,n)
                f(j,i,n){
                    v[0]=v[1]=0;
                    f(k,0,2)
                        f(oi,max(i-1,0),i+2){
                            f(ok,0,2){
                                if(ok || oi==i+1){
                                    Add(v[k||(oi==i-1)],1ll*dp[x][i][j][k]*dp[u][oi][j][ok]%mod);
                                }
                            }
                        }
                    dp[x][i][j][0]=v[0];
                    dp[x][i][j][1]=v[1];
                }
        }
    }
}
int main(){
	cin>>n;
	f(i,1,n){
	    int u,v;
	    cin>>u>>v;
	    g[u].pb(v);
	    g[v].pb(u);
	}
	dfs(1,0);
	f(i,0,n)
	    f(j,0,n)
	        Add(res[j],dp[1][i][j][1]);
	f(i,1,n)
	    Add(ans,1ll*(res[i]-res[i-1]+mod)*i%mod);
	Add(ans,n+1);
	ans=(ans-pow(2,n,mod)+mod)%mod;
    cout<<1ll*ans*pow(pow(2,n,mod),mod-2,mod)%mod;
}