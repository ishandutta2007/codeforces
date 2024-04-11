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

const int N=1e6+9,mod=1e9+7;

//math
int fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

int n,m,ans,res,p=1;

int main(){
    make_fac();
    cin>>n>>m;
    ans=1ll*fac[n-2]*C(n-2,m-1)%mod;
    f(i,1,n-1)
        Add(ans,1ll*C(n-i-2,m-1)*C(i,n-2)%mod*pow(n,i-1,mod)%mod*pow(m,i,mod)%mod*(n-i)%mod*fac[n-i-2]);
    cout<<ans;
}