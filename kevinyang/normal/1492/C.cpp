#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	string s,t;
	cin >> s >> t;
	vector<vector<int>>ind(26);
	for(int i = 0; i<n; i++){
		ind[s[i]-'a'].push_back(i+1);
	}
	for(int i = 0; i<26; i++){
		ind[i].push_back((int)2e9);
	}
	vector<int>left(m+5);
	vector<int>right(m+5);
	for(int i = 1; i<=m; i++){
		int letter = t[i-1]-'a';
		left[i] = *upper_bound(ind[letter].begin(),ind[letter].end(),left[i-1]);
	}
	right[m+1] = (int)1e9;
	for(int i = m; i>=1; i--){
		int letter = t[i-1]-'a';
		right[i] = *(lower_bound(ind[letter].begin(),ind[letter].end(),right[i+1])-1);
	}
	int ans = 0;
	for(int i = 1; i<m; i++){
		ans = max(ans,right[i+1]-left[i]);
	}
	cout << ans << "\n";
	return 0;
}