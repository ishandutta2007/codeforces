#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int k;
lint dp[33][33][3];

lint f(int pos, int bag, int exc){
	if(pos == -1) return 1;
	if(~dp[pos][bag][exc]) return dp[pos][bag][exc];
	if(exc && (k >> pos) % 2 == 0){
		return dp[pos][bag][exc] = (f(pos-1, bag, exc) << max(bag-1, 0)) % mod;
	}
	lint ret = f(pos-1, bag+1, exc);
	if(bag > 0){
		ret += (f(pos-1, bag, exc) << (bag - 1)) % mod;
		ret %= mod;
	}
	ret += (f(pos-1, bag, 0) << max(bag-1, 0)) % mod;
	ret %= mod;
	return dp[pos][bag][exc] = ret;
}

int main(){
	cin >> k;
	memset(dp, -1, sizeof(dp));
	cout << f(31, 0, 1);
}