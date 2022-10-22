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

ll po(ll a,ll b=mod-2){
	ll ans=1;
	for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
	return ans;
}

void solve(){
	int n,k;
	cin>>n>>k;
	if(k*2-1>n){
		printf("-1\n");
		return;
	}
	vector<vector<char>> ans(n,vector<char>(n,'.'));
	for(int i=0;i<k;i++)ans[i*2][i*2]='R';
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%c",ans[i][j]);
		}
		printf("\n");
	}
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