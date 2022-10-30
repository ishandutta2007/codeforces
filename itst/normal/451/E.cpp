#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
ll f[21] , S , N;

int poww(ll a , int b){
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

ll binom(ll a , ll b){
	a %= MOD;
	if(a < b) return 0;
	ll times = 1 , jc = 1;
	for(int i = a ; i > a - b ; --i){
		times = times * i % MOD;
		jc = jc * (a - i + 1) % MOD;
	}
	return times * poww(jc , MOD - 2) % MOD;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	cin >> N >> S;
	for(int i = 0 ; i < N ; ++i)
		cin >> f[i];
	ll ans = 0;
	for(int i = 0 ; i < 1 << N ; ++i){
		ll p = 0 , flg = 1;
		for(int j = 0 ; j < N ; ++j)
			if(i >> j & 1){
				p += f[j] + 1;
				flg = MOD - flg;
			}
		ans = (ans + flg * binom(S - p + N - 1 , N - 1)) % MOD;
	}
	cout << ans;
	return 0;
}