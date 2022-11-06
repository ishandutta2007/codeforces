#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	vector<int>freq(26);
	int n = s.length();
	int ans = 0;
	for(int i = 0; i<n; i++){
		freq[s[i]-'a']++;
		ans = max(ans,freq[s[i]-'a']);
	}
	for(int i = 0; i<26; i++){
		freq[i] = 0;
	}
	vector<vector<int>>cnt(26,vector<int>(26));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<26; j++){
			cnt[j][s[i]-'a']+=freq[j];
		}
		freq[s[i]-'a']++;
	}
	for(int i = 0; i<26; i++){
		for(int j = 0; j<26; j++){
			ans = max(ans,cnt[i][j]);
		}
	}
	cout << ans << "\n";
	return 0;
}