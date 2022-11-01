#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>
#include<cassert>
#include<algorithm>
using namespace std;

const int MOD = 1e9 + 7;
int dp[100003]; string s;

signed main(){
	cin >> s; dp[0] = dp[1] = 1;
	for(int i = 2 ; i <= s.size() ; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	int pos = 0 , ans = 1;
	while(pos < s.size()){
		int pos1 = pos;
		while(pos1 < s.size() && s[pos1] == s[pos]) ++pos1;
		ans = 1ll * ans * (s[pos] == 'u' || s[pos] == 'n' ? dp[pos1 - pos] : (s[pos] == 'm' || s[pos] == 'w' ? 0 : 1)) % MOD;
		pos = pos1;
	}
	cout << ans;
	return 0;
}