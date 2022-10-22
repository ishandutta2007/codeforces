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
const int mn=4e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=31607;

int a[mn];

ll solve(int n){
	int num=0;
	ll ans=0;
	for(int i=0;i<n;i++) {
		if(a[i]&1) {
			if(num<0) ans+= -num;
			++num;
		}
		else {
			if(num>0) ans+=num-1;
			--num;
		}
	}
	if(num>1||num<0) return 0x3f3f3f3f3f3f3f3f;
	return ans;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	while(tc--) {
		int n;
		cin >> n;
		for(int i=0;i<n;i++)cin>>a[i];
		int nodd = 0;
		for(int i=0;i<n;i++)if(a[i]&1)nodd++;
		ll f = solve(n);
		for(int i=0;i<n;i++)a[i]^=1;
		ll g = solve(n);
		ll ans = min(f,g);
		printf("%lld\n",ans > 1e15 ? -1 : ans);
	}
}