#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const lint oo = 2e18;
int n;
string s;

lint dp[555];

lint gob(lint x, lint y){
	if(3e18 / y <= x) return oo;
	return min(oo, x * y);
}

lint cost(int s, int e){
	lint ans = 0;
	for(int i=s; i<=e; i++){
		ans = ans * 10 + ::s[i] - '0';
	}
	return ans;
}

lint f(int pos){
	if(pos == 0) return 0;
	if(~dp[pos]) return dp[pos];
	lint ret = 1e18;
	if(s[pos - 1] == '0') ret = gob(f(pos - 1), n);
	for(int i=pos-1; i>=0 && i >= pos-11; i--){
		if(s[i] == '0') continue;
		if(cost(i, pos - 1) >= n) break;
		ret = min(ret, gob(f(i), n) + cost(i, pos - 1));
	}
	return dp[pos] = ret;
}

int main(){
	cin >> n >> s;
	memset(dp, -1, sizeof(dp));
	cout << f(s.size());
}