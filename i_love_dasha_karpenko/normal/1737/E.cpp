#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e6+7;
const ll MOD = 1e9+7;
ll binpow(ll x,int power){
	ll mult = x%MOD;
	x = 1;
	while(power){
		if (power&1){
			x = x*mult%MOD;
		}
		power /= 2;
		mult = mult*mult%MOD;
	}
	return x;
}
ll sum[N],ans[N],pr[N],rev2;
void solve(){
	int n;
	cin>>n;
	sum[n+1] = 0;
	for(int i = n;i>=1;i-=1){
		sum[i] = sum[i+1];
		ans[i] = pr[(i+1)/2-(i==n)]*(MOD+1-sum[min(n+1,i*2)]) % MOD;
		while(ans[i]>=MOD){
			ans[i] -= MOD;
		}
		sum[i] = (sum[i]+ans[i]);
		if (sum[i]>=MOD){
			sum[i] -= MOD;
		}
	}
	for(int i = 1;i<=n;i+=1){
		cout<<ans[i]<<'\n';
	}
}
signed main(){
	rev2 = binpow(2,MOD-2);
	pr[0] = 1;
	for(int i = 1;i<N;i+=1){
		pr[i] = pr[i-1]*rev2%MOD;
	}
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}