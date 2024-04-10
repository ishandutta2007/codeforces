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
const int mn=3e5+10;
ll d[mn];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)cin>>d[i];
		sort(d,d+n);
		ll ans = d[n-1],sum=0;
		for(int i=1;i<n;i++){
			ans-=d[i]*i-sum;
			sum+=d[i];
		}
		printf("%lld\n",ans);
	}
}