#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[100005], cur;

vector<ll> x[66];

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		cur ^= a[i];
		for(ll j=1;j<=60;j++) {
			if(a[i]<(1ll<<j)) {
				x[j-1].push_back(a[i]); break;
			}
		}
	}
	vector<ll> ans;
	for(ll i=1;i<=n;i++) {
		bool flag = false;
		for(ll j=0;j<60;j++) {
			if((cur & (1ll<<j)) && !x[j].empty()) {
				ans.push_back(x[j].back());
				x[j].pop_back(); flag = true; break;
			}
		}
		if(!flag) {puts("No"); return 0;}
		cur ^= ans.back();
	}
	puts("Yes");
	for(ll i=ans.size();i--;) printf("%lld ",ans[i]);
	puts("");
}