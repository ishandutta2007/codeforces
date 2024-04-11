#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
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

const int N=5005,mod=1e9+7,S=30;

int n,t,ans,last[N],dp[N][N],sum[N][N],nxt[N][S];
string s;
vector<int> v;

int fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

int calc(int x){
	return C(x-1,n-1);
}

int main(){
	make_fac();
	fill(last,last+N,-1);
	cin>>n>>s;
	s=' '+s;
	sum[0][0]=1;
	f(i,1,n+1){
		sum[i][0]=1;
		f(j,1,n+1){
			dp[i][j]=sum[i-1][j-1];
			if(last[s[i]-'a']!=-1){
				Add(dp[i][j],mod-sum[last[s[i]-'a']][j-1]);
			}
			sum[i][j]=(sum[i-1][j]+dp[i][j])%mod;
			Add(ans,1ll*dp[i][j]*calc(j)%mod);
		}
		last[s[i]-'a']=i;
	}
	cout<<ans;
}