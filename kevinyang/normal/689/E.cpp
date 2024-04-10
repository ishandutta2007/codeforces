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
	int n,k;
	cin >> n >> k;
	vector<pair<int,int>>arr(n+1);
	vector<int>sorted;
	set<int>st;
	map<int,int>add;
	for(int i = 1; i<=n; i++){
		int x,y;
		cin >> x >> y;
		arr[i] = {x,y+1};
		st.insert(x); st.insert(y+1);
		add[x]++; add[y+1]--;
	}
	for(int nxt: st){
		sorted.push_back(nxt);
	}
	int cur = 0;
	int ans = 0;
	for(int i = 0; i+1<sorted.size(); i++){
		int len = sorted[i+1]-sorted[i];
		cur+=add[sorted[i]];
		ans+=choose(cur,k)*len%mod;
		ans%=mod;
	}
	cout << ans << "\n";
	return 0;
}