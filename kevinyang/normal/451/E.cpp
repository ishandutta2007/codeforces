#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>fact(2000010);
vector<int>inv(2000010);
const int mod = (int)1e9+7;
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
int choose(int x, int y){
	if(y>x)return 0;
	int ans = inv[y];
	for(int i = x-y+1; i<=x; i++){
		ans*=(i%mod); ans%=mod;
	}
	return ans; 
}
int permute(int x, int y){
	if(y>x)return 0;
	return (fact[x]*inv[x-y])%mod;
}
void precalc(){
	fact[0] = 1; inv[0] = 1;
	for(int i = 1; i<=2000000; i++){
		fact[i] = fact[i-1]*i%mod;
	}
	inv[2000000] = modpow(fact[2000000],mod-2);
	for(int i = 1999999; i>0; i--){
		inv[i] = inv[i+1]*(i+1)%mod;
	}
}
signed main(){
	precalc();
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,s;
	cin >> n >> s;
	/*
	Idea: shit out gen func
	G(x) = product of (1+x+x^2+x^3...+x^(fi)) for all i
	G(x) = (1-x)^(-n) * (1-x^(fi+1)) for all i
	


	*/
	vector<int>arr(n);
	//cout << choose(4,1) << "\n";
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	int ans = 0;
	for(int i = 0; i<(1<<n); i++){
		int sum = 0;
		for(int j = 0; j<n; j++){
			if(i&(1<<j)){
				sum+=arr[j]+1;
			}
		}
		if(sum>s)continue;
		int v = choose(n+s-sum-1,n-1);
		if(__builtin_popcount(i)%2==0)ans+=v;
		else ans-=v;
		ans+=mod; ans%=mod;
		//cout << i << " " << v << "\n";
	}
	cout << ans << "\n";
	return 0;
}