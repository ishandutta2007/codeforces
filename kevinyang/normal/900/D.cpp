#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>dp;
const int mod = (int)1e9+7;//change this if needed
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
vector<int> factor(int x){
	vector<int>ret;
	for(int i = 1; i*i<=x; i++){
		if(x%i==0){
			ret.push_back(i);
			if(i!=x/i&&i>1)ret.push_back(x/i);
		}
		
	}
	return ret;
}
int f(int x){
	if(x==1)return 1;
	if(dp.count(x))return dp[x];
	vector<int>arr = factor(x);
	int v = modpow(2,x-1);
	for(int nxt: arr){
		v-=f(nxt);
		v+=mod; v%=mod;
	}
	return dp[x] = v;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int x,y;
	cin >> x >> y;
	if(y%x==0){
		cout << f(y/x) << "\n";
	}
	else{
		cout << "0\n";
	}
	return 0;
}