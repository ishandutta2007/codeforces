#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e6 + 3;

lint ipow(int x, int p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}

vector<int> berlekamp_massey(vector<int> x){
	vector<int> ls, cur;
	int lf, ld;
	for(int i=0; i<x.size(); i++){
		lint t = 0;
		for(int j=0; j<cur.size(); j++){
			t = (t + 1ll * x[i-j-1] * cur[j]) % mod;
		}
		if((t - x[i]) % mod == 0) continue;
		if(cur.empty()){
			cur.resize(i+1);
			lf = i;
			ld = (t - x[i]) % mod;
			continue;
		}
		lint k = -(x[i] - t) * ipow(ld, mod - 2) % mod;
		vector<int> c(i-lf-1);
		c.push_back(k);
		for(auto &j : ls) c.push_back(-j * k % mod);
		if(c.size() < cur.size()) c.resize(cur.size());
		for(int j=0; j<cur.size(); j++){
			c[j] = (c[j] + cur[j]) % mod;
		}
		if(i-lf+(int)ls.size()>=(int)cur.size()){
			tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % mod);
		}
		cur = c;
	}
	for(auto &i : cur) i = (i % mod + mod) % mod;
	return cur;
}


int main(){
	vector<int> dp(50);
	for(int i=0; i<50; i++){
		cout << "? " << i << endl;
		int x; cin >> x;
		dp[i] = x;
	}
	auto rec = berlekamp_massey(dp);
	dp.resize(1000003);
	for(int i=50; i<1000003; i++){
		for(int j=0; j<rec.size(); j++){
			dp[i] += 1ll * dp[i - j - 1] * rec[j] % mod;
			dp[i] %= mod;
		}
	}
	for(int i=0; i<1000003; i++){
		if(dp[i] == 0){
			cout << "! " << i << endl;
			return 0;
		}
	}
	puts("! -1");
	return 0;
}