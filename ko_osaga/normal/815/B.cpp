#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;


const int mod = 1e9 + 7;

lint ipow(lint x, lint p){
	lint ret = 1, piv = x % mod;
	while(p){
		if(p&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret % mod;
}

int n, a[200005];

lint fact[100005], invf[100005];

lint bino(int x, int y){
	return fact[x] * (invf[y] * invf[x-y] % mod) % mod;
}

int main(){
	fact[0] = invf[0] = 1;
	for(int i=1; i<=100000; i++){
		fact[i] = fact[i-1] *i  %mod;
		invf[i] = ipow(fact[i], mod-2);
	}
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	int par = 1;
	while(n % 4 != 1){
		int tmp[200005] = {};
		for(int j=0; j<n-1; j++){
			if(par) tmp[j] = a[j] + a[j+1];
			else tmp[j] = a[j] - a[j+1] + mod;
			tmp[j] %= mod;
			par ^= 1;
		}
		memcpy(a, tmp, sizeof(a));
		n--;
	}
	lint ret = 0;
	for(int i=0; i<n; i+=2){
		ret += bino(n/2, i/2) * a[i] % mod;
		ret %= mod;
	}
	cout << ret;
}