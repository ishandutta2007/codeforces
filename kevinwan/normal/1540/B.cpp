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

vi g[mn];
int d[mn][mn];

void dfs(int x,int p,int d[mn]){
	for(int y:g[x])if(y!=p){
		d[y]=d[x]+1;
		dfs(y,x,d);
	}
}
ll ch[mn][mn];
ll pbin[mn][mn];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	ch[0][0]=1;
	for(int i=1;i<mn;i++){
		ch[i][0]=1;
		for(int j=1;j<=i;j++)ch[i][j]=(ch[i-1][j-1]+ch[i-1][j])%mod;
	}
	for(int i=1;i<mn;i++)pbin[0][i]=1;
	for(int i=1;i<mn;i++){
		pbin[i][0]=0;
		for(int j=1;i+j<mn;j++){
			pbin[i][j]=po(2,mod-1-(i+j-1))*ch[i+j-2][j-1];
			pbin[i][j]+=pbin[i][j-1],pbin[i][j]%=mod;
		}
	}
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=1;i<=n;i++)dfs(i,i,d[i]);
	//cerr<<po(3)*3%mod<<endl;
	ll ans=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		int dis=d[i][j];
		ll pi=0;
		for(int k=1;k<=n;k++){
			ll bias=d[i][k]-d[j][k];
			ll p=(-bias+dis)/2;
			ll q=(bias+dis)/2;
			//cerr<<i<<" "<<j<<" "<<k<<" "<<p<<" "<<q<<" "<<pbin[p][q]<<endl;
			pi+=pbin[p][q];
		}
		//cerr<<pi<<endl<<endl;
		ans+=pi,ans%=mod;
	}
	ans*=po(n),ans%=mod;
	if(ans<0)ans+=mod;
	printf("%lld\n",ans);
}