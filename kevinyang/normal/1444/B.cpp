#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>fact(2000010);
vector<int>inv(2000010);
const int mod = 998244353;
int power(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * power((x * x) % mod, y / 2)) % mod;
}
int choose(int x, int y){
	if(y>x)return 0;
	return (fact[x]*inv[y]%mod)*inv[x-y]%mod;
}
int permute(int x, int y){
	if(y>x)return 0;
	return (fact[x]*inv[x-y])%mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	fact[0] = 1; inv[0] = 1;
	for(int i = 1; i<=2000000; i++){
		fact[i] = fact[i-1]*i%mod;
	}
	inv[2000000] = power(fact[2000000],mod-2);
	for(int i = 1999999; i>0; i--){
		inv[i] = inv[i+1]*(i+1)%mod;
	}
	int n;
	cin >> n;
	vector<int>arr(2*n);
	for(int i = 0; i<2*n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	int ans = 0;
	for(int i = 0; i<n; i++){
		ans+=-1*arr[i]+arr[n+i];
	}
	ans%=mod;
	ans*=choose(2*n,n);
	ans%=mod;
	cout << ans << "\n";
}