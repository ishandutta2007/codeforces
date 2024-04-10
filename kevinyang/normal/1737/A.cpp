#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int>freq(26);
		for(int i = 0; i<n; i++){
			freq[s[i]-'a']++;
		}
		string ans = "";
		k = n/k;
		for(int i = 0; i<n/k; i++){
			int val = 25;
			int rem = k;
			int cur = 0;
			while(rem>0&&freq[cur]>0){
				rem--;
				freq[cur]--;
				cur++;
			}
			ans.push_back((char)('a'+cur));
		}
		cout << ans << "\n";
	}
	return 0;
}