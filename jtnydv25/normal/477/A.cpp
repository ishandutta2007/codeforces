#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int mod = 1e9 + 7;
ll inv2 = (mod + 1) / 2;
ll sm2(ll x){
	if(x >= mod) x %= mod;
	return (((x * (x + 1)) % mod) * inv2)% mod;
}

int main(){
	ll a, b;
	cin >> a >> b;
	ll sm1 = 0, sm = 0;
	for(ll l = 1; l < b; l++){
		ll mx = a;
		ll mn = 1;
		sm1 += (l * (sm2(mx) - sm2(mn - 1))) % mod;
		sm = (sm + ((mx - mn + 1) % mod) * l) % mod;
	}
	sm1 = (sm1 % mod + mod) % mod;
	cout << (b * sm1 + sm) % mod;
}