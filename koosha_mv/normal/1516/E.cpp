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

const int N=405,mod=1e9+7;

int n,k,dp[N][N],C[N][N],fac[N],inv[N],res[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
int c(int k,int n){
    int ans=1;
    if(k>n) return 0;
    f(i,n-k+1,n+1)
        ans=1ll*ans*i%mod;
    ans=1ll*ans*inv[k]%mod;
    return ans;
}
int main(){
    fac[0]=1;
    f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod,inv[i]=pow(fac[i],mod-2,mod);
    f(i,0,N)
        f(j,i,N){
            if(i==0) C[i][j]=1;
            else C[i][j]=(C[i][j-1]+C[i-1][j-1])%mod;
        }
    dp[0][0]=1;
    f(i,1,N)
        f(j,i*2,N)
            f(k,2,N)
                Add(dp[i][j],1ll*dp[i-1][j-k]*C[k-1][j-1]%mod*fac[k-1]%mod);
    cin>>n>>k;
    res[0]=1;
    f(i,1,k+1){ 
        int ans=0;
        f(j,i,min(N,n+1)){
            Add(ans,1ll*c(j,n)*dp[j-i][j]%mod);
            //cout<<j<<" "<<c(j,n)<<" "<<dp[j-i][j]<<endl;
        }
        res[i]=ans;
        if(1<i) Add(res[i],res[i-2]);
        cout<<res[i]<<" ";
    }
            
}