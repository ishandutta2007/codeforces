#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

bool f3(ll x,ll y){
	ll h = x^y;
	int cnt = 0;
	while(h>0){
		if(h%2){
			cnt++;
		}
		h >>=1;
	}
	return cnt%3==0;
}
typedef vector< vector< ll > >  vvll;
vvll g,gg,h,g0;
int n;

void mult(vvll &x, vvll &y, vvll&r){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			r[i][j] = 0;
			for(int k=0;k<n;k++){
				r[i][j] = (r[i][j]+x[i][k]*1LL*y[k][j])%mod;
			}
		}
	}
}

void binpow(ll p){
	if(p==1){
		return;
	}
	binpow(p/2);
	gg = g;
	h = g;
	mult(gg,h,g);
	if(p%2){
		h = g0;
		gg = g;
		mult(gg,h,g);
	}
}

int main()
{
	ll k;
	cin >> n >> k;
	ll a;
	vector<ll> v;
	for(int i=0;i<n;i++){
		cin >> a;
		v.push_back(a);
	}
	g.resize(n,vector<ll>(n,0));
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(f3(v[i],v[j])){
				g[i][j] = 1;
				g[j][i] = 1;
			}
		}
	}
	g0 = g;
	if(k==1){
		cout << n;
	}else{
		binpow(k-1);
		vector<int> d(n,1);
		ll ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ans += g[i][j];
				ans %= mod;
			}
		}
		cout << ans;
	}
}