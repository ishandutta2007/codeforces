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
		vector<int>freq(10);
		for(int i = 0; i<n; i++){
			freq[s[i]-'0']++;
		}
		vector<int>ans(n);
		char cur = '0';
		for(int i = 0; i<n; i++){
			while(cur<='9'&&freq[cur-'0']==0){
				cur++;
			}
			if(cur>'9')break;
			if(s[i]==cur){
				freq[s[i]-'0']--;
				ans[i] = 1;
			}
		}
		for(int i = 0; i<n; i++){
			if(ans[i]==1)continue;
			while(cur<='9'&&freq[cur-'0']==0){
				cur++;
			}
			if(cur>'9')break;
			if(s[i]==cur){
				freq[s[i]-'0']--;
				ans[i] = 2;
			}
		}
		int val = count(ans.begin(),ans.end(),0);
		if(val>0)cout << "-\n";
		else{
			for(int nxt: ans)cout << nxt;
			cout << "\n";
		}
	}
	return 0;
}