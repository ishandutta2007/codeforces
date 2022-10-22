#include <bits/stdc++.h>
using namespace std;
 
const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=1e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=1e9+7;


ll a[500][500];
void solve(){
	int n;
	cin>>n;
	for(int i=0;i<2*n;i++)for(int j=0;j<2*n;j++)cin>>a[i][j];
	ll ans=0;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)ans+=a[n+i][n+j];
	ans+=min({a[n][0],a[n][n-1],a[n-1][n],a[0][n],a[0][n*2-1],a[n-1][n*2-1],a[n*2-1][0],a[n*2-1][n-1]});
	printf("%lld\n",ans);
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}