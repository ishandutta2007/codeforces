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
	inv[2000000] = modpow(fact[2000000],mod-2);
	for(int i = 1999999; i>0; i--){
		inv[i] = inv[i+1]*(i+1)%mod;
	}
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>arr(n);
		vector<int>freq(n+1);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			freq[arr[i]]++;
		}
		sort(arr.begin(),arr.end());
		reverse(arr.begin(),arr.end());
		vector<int>freq2(n+1);
		for(int i = 0; i<k; i++){
			freq2[arr[i]]++;
		}
		int ans = 1;
		for(int i = 1; i<=n; i++){
			ans*=choose(freq[i],freq2[i]);
			ans%=mod;
		}
		cout << ans << "\n";
	}
}