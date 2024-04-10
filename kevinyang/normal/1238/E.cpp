#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<vector<int>>freq(m,vector<int>(m));
	for(int i = 1; i<s.length(); i++){
		if(s[i]==s[i-1])continue;
		freq[s[i-1]-'a'][s[i]-'a']++;
		freq[s[i]-'a'][s[i-1]-'a']++;
	}
	//cerr << "nae\n";
	vector<int>invpow(1<<m);
	for(int i = 0; i<m; i++){
		invpow[1<<i] = i;
	}
	//err << "nae\n";
	vector<vector<int>>cnt(m,vector<int>(1<<m));
	for(int j = 0; j<m; j++){
		for(int i = 1; i<(1<<m); i++){
			int v = i&-i;
			cnt[j][i] = cnt[j][i^v]+freq[j][invpow[v]];
			//cout << j << " " << i << " " << cnt[j][i] << "\n";
		}
	}
	//cerr << "nae\n";
	//cerr << "nae2\n";
	vector<int>dp(1<<m,(int)1e18);
	//cerr << "nae3\n";
	dp[0] = 0;
	for(int i = 0; i+1<(1<<m); i++){
		//cerr << "nae\n";
		int add = 0; int msk = ((1<<m)-1)^i;
		for(int j = 0; j<m; j++){
			if(i&(1<<j)){
				add+=cnt[j][msk];
			}
		}
		for(int j = 0; j<m; j++){
			if(i&(1<<j))continue;
			dp[i^(1<<j)] = min(dp[i^(1<<j)],add+dp[i]);
		}
		//cerr << "nae\n";
	}
	cout << dp[(1<<m)-1] << "\n";
	return 0;
}