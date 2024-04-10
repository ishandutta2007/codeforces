#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	vector<vector<vector<int>>>freq(10,vector<vector<int>>(200006,vector<int>(10)));
	for(int d = 0; d<10; d++){
		freq[d][0][d] = 1;
		for(int i = 0; i<200005; i++){
			for(int j = 0; j<9; j++){
				freq[d][i+1][j+1]+=freq[d][i][j];
				freq[d][i+1][j+1]%=mod;
			}
			freq[d][i+1][1]+=freq[d][i][9]; freq[d][i+1][0]+=freq[d][i][9];
			freq[d][i+1][1]%=mod; freq[d][i+1][0]%=mod;
		}
	}
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<int>freq2(10);
		string s = to_string(n);
		for(int i = 0; i<s.length(); i++){
			freq2[s[i]-'0']++;
		}
		int ans = 0;
		for(int i = 0; i<10; i++){
			for(int j = 0; j<10; j++){
				ans+=freq2[i]*freq[i][m][j]%mod;ans%=mod;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}