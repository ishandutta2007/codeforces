#include <bits/stdc++.h>
#define sz(v) ((int)((v).size()))
using namespace std;
using lint = long long;
const int mod = 998244353;

lint fact[300005];

lint good(vector<lint> v){
	sort(v.begin(), v.end());
	lint ret = 1;
	for(int i=0; i<sz(v); ){
		int e = i;
		while(e < sz(v) && v[i] == v[e]) e++;
		ret *= fact[e - i];
		ret %= mod;
		i = e;
	}
	return ret;
}
lint good2(vector<lint> v){
	sort(v.begin(), v.end());
	lint ret = 1;
	int tmp = 0;
	for(int i=0; i<sz(v); ){
		int e = i;
		while(e < sz(v) && v[i] == v[e]) e++;
		if(tmp > (v[i] & 1048575)) return 0;
		tmp = v[i] & 1048575;
		ret *= fact[e - i];
		ret %= mod;
		i = e;
	}
	return ret;
}
int main(){
	vector<lint> v1, v2, v3;
	int n; scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x, y; scanf("%d %d",&x,&y);
		v1.push_back(x);
		v2.push_back(y);
		v3.push_back(x * (1ll << 20) + y);
	}
	fact[0] = 1;
	for(int i=1; i<300005; i++) fact[i] = fact[i-1] * i % mod;
	lint ans = (good(v1) + good(v2) + mod - good2(v3)) % mod;
	ans = fact[n] + mod - ans;
	cout << ans % mod << endl;
}