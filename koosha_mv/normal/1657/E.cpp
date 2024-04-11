#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
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
#define int ll

const int N=500,mod=998244353;

int n,k,ans,a[N],dp[N][N];

int fact[N],ifact[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void math(){fact[0]=1; f(i,1,N) fact[i]=1ll*fact[i-1]*i%mod; ifact[N-1]=pow(fact[N-1],mod-2,mod);f_(i,N-2,0) ifact[i]=1ll*ifact[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fact[n]*ifact[n-k]%mod*ifact[k]%mod;}

main(){
	math();
	cin>>n>>k;
	/*f(i,1,k+1){
		f(t,1,n){
			f(p,0,n-t){
				if(p+t>=n) continue ;
				int res=1ll*C(t,n-1)*C(p,n-t-1)%mod,cnt=t*(t-1)/2+t*p;
				cout<<i<<" "<<t<<" "<<p<<" -> "<<res<<" "<<cnt<<" "<<(k-i+1)<<endl;
				Add(ans,1ll*res*pow(k-i+1,cnt,mod)%mod%mod);
			}
		}
	}
	cout<<ans<<endl;*/
	dp[0][0]=1;
	f(i,1,k+1){
		f(cnt,0,n){
			f(p,0,cnt+1){
				int t=p*cnt-p*(p+1)/2;
				Add(dp[i][cnt],1ll*dp[i-1][cnt-p]*pow(k-i+1,t,mod)%mod*C(p,(n-(cnt-p)-1))%mod);
			}
			//cout<<i<<" "<<cnt<<" "<<dp[i][cnt]<<endl;
		}
	}
	cout<<dp[k][n-1];
}