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
const int mn=2e5+10;
const ll mod=998244353;

ll dp[mn],ps[mn];
vector<ll> x, y;
bool st[mn];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	x.resize(n+1),y.resize(n+1);
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i]>>st[i];
	for(int i=1;i<=n;i++){
		int l=lower_bound(x.begin()+1,x.begin()+1+n,y[i])-x.begin();
		dp[i]=(x[i]-y[i]+ps[i-1]-ps[l-1])%mod;
		ps[i]=(ps[i-1]+dp[i])%mod;
        cerr<<dp[i]<<endl;
	}
	ll ans=(x[n]+1)%mod;
	for(int i=1;i<=n;i++)if(st[i])ans=(ans+dp[i])%mod;
    ans%=mod;
	if(ans<0)ans+=mod;
	printf("%lld\n",ans);
}