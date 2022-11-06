#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>fact(2000010);
vector<int>inv(2000010);
const int mod = 998244353;
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
bool comp(pair<int,int>a, pair<int,int>b){
	return a.second<b.second;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false); precalc();
	int n;
	cin >> n;
	vector<pair<int,int>>arr(n+1);
	for(int i = 1; i<=n; i++){
		int x,y;
		cin >> x >> y;
		arr[i] = {x,y};
	}
	sort(arr.begin(),arr.end());
	int ans = 0;
	if(true){
		vector<int>freq(n+1);
		for(int i = 1; i<=n; i++){
			freq[arr[i].first]++;
		}
		int cnt = 1;
		for(int i = 1; i<=n; i++){
			cnt*=fact[freq[i]];
			cnt%=mod;
		}
		ans+=cnt;
	}
	if(true){
		sort(arr.begin(),arr.end(),comp);
		vector<int>freq(n+1);
		for(int i = 1; i<=n; i++){
			freq[arr[i].second]++;
		}
		int cnt = 1;
		for(int i = 1; i<=n; i++){
			cnt*=fact[freq[i]];
			cnt%=mod;
		}
		ans+=cnt;
		ans%=mod;
	}
	if(true){
		sort(arr.begin(),arr.end());
		map<pair<int,int>,int>freq;
		set<pair<int,int>>s;
		bool f = true;

		for(int i = 1; i<=n; i++){
			freq[arr[i]]++;
			if(arr[i].first<arr[i-1].first)f = false;
			if(arr[i].second<arr[i-1].second)f = false;
			s.insert(arr[i]);
		}
		int cnt = 1;
		for(auto nxt: s){
			cnt*=fact[freq[nxt]];
			cnt%=mod;
		}
		if(f){
			ans-=cnt; ans+=mod;
			ans%=mod;
		}
		
	}
	ans = fact[n]-ans;
	ans+=mod; ans%=mod;
	cout << ans << "\n";
	return 0;
}