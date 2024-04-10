#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>fact(2000010);
vector<int>inv(2000010);
int mod = (int)1e9+7;
int power(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * power((x * x) % mod, y / 2)) % mod;
}
int choose(int x, int y){
	return (fact[x]*inv[y]%mod)*inv[x-y]%mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n = 2000009;
	fact[0] = 1; inv[0] = 1;
	for(int i = 1; i<=n; i++){
		fact[i] = fact[i-1]*i%mod;
	}
	inv[n] = power(fact[n],mod-2);
	for(int i = n-1; i>0; i--){
		inv[i] = inv[i+1]*(i+1)%mod;
	}
	int q;
	cin >> q;
	while(q--){
		set<int>s;
		map<int,int>hm;
		int x,y;
		cin >> x >> y;
		swap(x,y);
		for(int i = 2; i*i<=y; i++){
			while(y%i==0){
				y/=i;
				s.insert(i);
				hm[i]++;
			}
		}
		if(y>1){
			hm[y]++;
			s.insert(y);
		}
		int ans = 1;
		for(int nxt: s){
			int val = hm[nxt];
			ans*=choose(val+x-1,x-1);
			ans%=mod;
		}
		ans*=power(2,x-1);
		ans%=mod;
		cout << ans << "\n";
	}
	return 0;
}