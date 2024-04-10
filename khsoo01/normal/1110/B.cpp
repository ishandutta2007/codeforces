#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, m, k;
vector<ll> v;

int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	k = n - k;
	for(ll i=1,j;i<=n;i++) {
		ll T;
		scanf("%lld",&T);
		if(i != 1) v.push_back(T - j - 1);
		j = T;
	}
	sort(v.begin(), v.end());
	ll ans = n;
	for(auto &T : v) {
		if(!k) break;
		k--;
		ans += T;
	}
	printf("%lld\n",ans);
}