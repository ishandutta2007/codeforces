#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y)
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x)
#define gett(x) scanf("%d",&x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+99,mod=1e9+7,sq=333;

int fac[N],ifac[N],Pow[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

int n,m,k,dp[N];
string s;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	make_fac();
	Pow[0]=1;
	f(i,1,N)
		Pow[i]=25ll*Pow[i-1]%mod;
	cin>>m>>s;
	k=s.size();
	f(i,0,m+1){
		int type=1;
		if(i) cin>>type;
		if(type==1){
			if(i) cin>>s;
			k=s.size();
			if(k>sq){
				dp[0]=1;
				f(i,1,N){
					dp[i]=25ll*dp[i-1]%mod;
					int res=(dp[i-1]+mod-1ll*C(k-1,i-1)*Pow[i-1-(k-1)]%mod)%mod;
					Add(dp[i],res);
					//cout<<i<<" "<<dp[i]<<endl;
				}
			}
		}
		else{
			cin>>n;
			int ans=pow(26,n,mod);
			if(k<=sq){
				f(i,0,k)
					Add(ans,mod-1ll*C(i,n)*Pow[n-i]%mod);
				cout<<ans<<'\n';
			}
			else{
				Add(ans,mod-dp[n]);
				cout<<ans<<'\n';
			}
		}
	}
}