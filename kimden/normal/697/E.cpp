#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;



ll binpow(ll a,ll p){
	if(p==0){
		return 1;
	}
	if(p==1){
		return a;
	}
	ll x,y;
	x = y = binpow(a,p/2);
	x *= y;
	x%=mod;
	if(p%2){
		x*=a;
		x%=mod;
	}
	return x;
}

int main()
{
	int k;
	cin >> k;
	ll t;
	ll a=2;
	bool even = false;
	for(int i=0;i<k;i++){
		cin >> t;
		if(t%2==0){
			even = true;
		}
		a = binpow(a,t);
	}
	a *= 500000004;
	a%=mod;
	ll ans1, ans2;
	ans2 = a;
	ans1 = a;
	if(even){
		ans1++;
		ans1%=mod;
	}else{
		ans1+=(mod-1);
		ans1%=mod;
	}
	ans1 *=333333336;
	ans1%=mod;
	cout << ans1 << "/" << ans2;
}