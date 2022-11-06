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
	int sum = 0;
	for(int i = 1; i<=n; i++){
		sum+=arr[i];
	}
	if(sum%n!=0){
		cout << "0\n";
		return 0;
	}
	int avg = sum/n;
	int low = 0; int eq = 0; int high = 0;
	for(int i = 1; i<=n; i++){
		if(arr[i]<avg)low++;
		else if(arr[i]==avg)eq++;
		else high++;
	}
	if(high<=1||low<=1){
		set<int>s;
		map<int,int>hm;
		for(int i = 1; i<=n; i++){
			s.insert(arr[i]);
			hm[arr[i]]++;
		}
		int ans = fact[n];
		for(int nxt: s){
			ans*=inv[hm[nxt]]; ans%=mod;
		}
		cout << ans << "\n";
	}
	else{
		int ans = fact[low]*fact[high]%mod;
		if(true){
			set<int>s;
			map<int,int>hm;
			for(int i = 1; i<=n; i++){
				if(arr[i]!=avg){
					s.insert(arr[i]);
					hm[arr[i]]++;
				}
			}
			for(int nxt: s){
				ans*=inv[hm[nxt]]; ans%=mod;
			}
		}
		ans*=choose(n,eq); ans%=mod; ans*=2; ans%=mod;
		cout << ans << "\n";
	}
	return 0;
}