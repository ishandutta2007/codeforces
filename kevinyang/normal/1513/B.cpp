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
	cin.tie(nullptr)->sync_with_stdio(false); precalc();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n); 
		map<int,int>freq; set<int>s;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			freq[arr[i]]++; 
			s.insert(arr[i]);
		}
		int sum = arr[0];
		for(int i = 0; i<n; i++){
			sum = sum&arr[i];
		}
		int cnt = 0;
		for(int i = 0; i<n; i++){
			if(sum==arr[i])cnt++;
		}
		if(cnt<=1){
			cout << "0\n";
			continue;
		}
		int ans = cnt*(cnt-1)%mod*fact[n-2]%mod;
		cout << ans << "\n";
	}
	return 0;
}