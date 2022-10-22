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

ll c[mn];


int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	ll ans =  0;
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<n;i+=2) {
		ll mi = 0;
		ll cur = 0;
		for(int j = i+1;j<n;j++){
			if((j-i)&1) {
				ll num = min(c[i]+mi+(mi<0),c[j]+mi-cur+(mi<cur));
				ans += max(num,0LL);
				//cerr << i << " " << j << " " <<  num << endl;
			}
			if(j&1)cur-=c[j];
			else cur+=c[j];
			mi=min(mi,cur);
		}
	}
	printf("%lld\n",ans);
}