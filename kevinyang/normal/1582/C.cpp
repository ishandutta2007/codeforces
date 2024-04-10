#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ispalindrome(string s){
	string s2 = s;
	reverse(s2.begin(),s2.end());
	return (s2==s);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = 0;
		bool f = false;
		for(int i = 0; i<26; i++){
			string s2 = "";
			for(int j = 0; j<n; j++){
				if(s[j]!=(char)('a'+i)){
					s2+=s[j];
				}
			}
			if(ispalindrome(s2)){
				int len = s2.length();
				vector<int>add;
				vector<int>add2;
				if(true){
					int cur = 0;
					for(char nxt: s){
						if(nxt==(char)('a'+i))cur++;
						else{
							add.push_back(cur);
							cur = 0;
						}
					}
					add.push_back(cur);
				}
				if(true){
					int cur = 0;
					reverse(s.begin(),s.end());
					for(char nxt: s){
						if(nxt==(char)('a'+i))cur++;
						else{
							add2.push_back(cur);
							cur = 0;
						}
					}
					reverse(s.begin(),s.end());
					add2.push_back(cur);
				}
				int total = len;
				assert(add.size()==add2.size());
				for(int i = 0; i<add.size(); i++){
					total+=min(add[i],add2[i]);
				}
				f = true;
				ans = max(ans,total);
			}
		}
		if(!f){
			cout << "-1\n";
			continue;
		}
		cout << n-ans << "\n";
	}
	return 0;
}