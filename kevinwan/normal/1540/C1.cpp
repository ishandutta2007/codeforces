#include <bits/stdc++.h>
using namespace std;
 
mt19937_64 rng(time(0));
const long double eps = 1e-15;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=300+10;
const ll mod=1e9+7;

ll po(ll a,ll b=mod-2){
	ll ans=1;
	for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
	return ans;
}

ll c[mn],b[mn];
ll ans[mn*2];
ll dp[2][10100];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>c[i];
	for(int i=1;i<n;i++)cin>>b[i],b[i]+=b[i-1];
	for(int i=1;i<n;i++)b[i]+=b[i-1];
	int ma=INT_MAX,mi=INT_MAX,sa=0,si=0;
	for(int i=0;i<n;i++){
		sa+=c[i];
		si+=0;
		ma=min(ll(ma),(sa-b[i])/(i+1)+1);
		mi=min(ll(mi),(si-b[i])/(i+1)-1);
	}
	//cerr<<mi<<" "<<ma<<endl;
	
	for(int m=mi;m<=ma;m++){
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=0;i<n;i++){
			ll lim = m*(i+1)+b[i];
			//cerr<<lim<<endl;
			for(int j=1;j<10100;j++)dp[0][j]+=dp[0][j-1],dp[0][j]%=mod;
			for(int j=0;j<10100;j++){
				dp[1][j]=(dp[0][j]-((j>=c[i]+1)?dp[0][j-c[i]-1]:0))%mod;
			}
			for(int j=0;j<min(lim,ll(10100));j++)dp[1][j]=0;
			memcpy(dp[0],dp[1],sizeof(dp[0]));
			memset(dp[1],0,sizeof(dp[1]));
		}
		for(int i=0;i<10100;i++)ans[m-mi]+=dp[0][i],ans[m-mi]%=mod;
		if(ans[m-mi]<0)ans[m-mi]+=mod;
	}
	int q;
	cin>>q;
	ll aa=1;
	for(int i=0;i<n;i++)aa*=c[i]+1,aa%=mod;
	for(int i=0;i<q;i++){
		ll x;
		cin>>x;
		if(x<mi){
			printf("%lld\n",aa);
		}
		else if(x>ma)printf("0\n");
		else printf("%lld\n",ans[x-mi]);
	}
}