#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int>freq(1000);
		freq[s[0]]++;
		bool f = true;
		for(int i = 1; i<n; i++){
			if(s[i]!=s[i-1]){
				if(freq[s[i]])f = false;
			}
			freq[s[i]]++;
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}