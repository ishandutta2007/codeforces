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
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>a(40);// frequencies of number of 2's in prime factorization
	for(int i = 1; i<=n; i++){
		int cnt = 0;
		while(arr[i]%2==0){
			arr[i]/=2;
			cnt++;
		}
		a[cnt]++;
	}
	vector<int>psa(40);
	for(int i = 35; i>=0; i--){
		psa[i] = psa[i+1]+a[i];
	}
	int ans = modpow(2,n)+mod-1;
	ans%=mod;
	for(int i = 1; i<=30; i++){
		for(int j = 1; j<=a[i]; j+=2){
			int v = choose(a[i],j)*modpow(2,psa[i+1])%mod;
			ans+=mod-v;
			ans%=mod;
		}
	}
	cout << ans << "\n";
	return 0;
}