//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n';
const int N = 3e5+7;
const ll MOD = 998244353;
ll dp[N];
ll add(ll a,ll b){
	a += b;
	if (a>=MOD){
		a -= MOD;
	}
	return a;
}
ll mult(ll a,ll b){
	return a*b%MOD;
}
ll fact[N],rev[N],spl[N],rv[N];
ll binpow(ll x,int power){
	ll mult = x%MOD;
	x = 1;
	while(power){
		if (power%2!=0){
			x = x*mult%MOD;
		}
		mult = mult*mult%MOD;
		power /= 2;
	}
	return x;
}
ll C(int n,int k){
	if (n<0 || n<k){
		return 0;
	}
	return mult(fact[n],mult(rev[k],rev[n-k]));
}
void solve(){
	int n;
	cin>>n;
	ll res = 0;
	ll pr = 1;
	for(int qtr = 1;qtr*4<=n;qtr+=1){
		pr = mult(pr,2);
		res = add(res,mult(pr,mult(spl[qtr*2],mult(C(n-qtr*2,qtr*2),dp[n-qtr*4]))));
	}
	cout<<add(dp[n],res)<<endl;
}
signed main(){
	fact[0] = 1;
	for(int i = 1;i<N;i+=1){
		fact[i] = mult(fact[i-1],i);
	}
	rev[N-1] = binpow(fact[N-1],MOD-2);
	for(int i = N-1;i>0;i-=1){
		rev[i-1] = mult(rev[i],i);
	}
	rv[0] = 1;
	for(int i = 1;i<N;i+=1){
		rv[i] = mult(rv[i-1],rev[2]);
	}
	spl[0] = 1;
	for(int i = 2;i<N;i+=2){
		spl[i] = mult(spl[i-2],i-1);
	}
	dp[0] = 1;
	for(int i = 1;i<N;i+=1){
		dp[i] = dp[i-1];
		if (i>=2){
			dp[i] = add(dp[i],mult(dp[i-2],i-1));
		}
	}
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}