#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.length();
	vector<int>freq(26);
	vector<int>ans(n+1);
	for(int i = 1; i<=n; i++){
		bool f = false;
		for(int j = 0; j<s[i-1]-'a'; j++){
			if(freq[j])f = true;
		}
		if(!f)ans[i] = 1;
		freq[s[i-1]-'a']++;
	}
	for(int i = 1; i<=n; i++){
		if(ans[i])cout << "Mike\n";
		else cout << "Ann\n";
	}
	return 0;
}