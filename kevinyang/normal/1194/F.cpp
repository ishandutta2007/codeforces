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
	int n,t;
	cin >> n >> t;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	int ans = 0;
	int sum = 0;
	int cur = 0;
	int cnt = 1;
	for(int i = 1; i<=n; i++){
		sum+=arr[i];
		cnt*=2; cnt+=mod-choose(i-1,cur);
		cnt%=mod;
		if(t-sum>=i){
			cur++;
			cnt++;
		}
		else{
			if(sum>t)break;
			while(cur>t-sum){
				cnt+=mod-choose(i,cur);
				cur--;
				cnt%=mod;
			}
		}
		int v = modpow(modpow(2,i),mod-2);
		ans+=cnt*v%mod;
		ans%=mod;
	}
	cout << ans << "\n";
	return 0;
}