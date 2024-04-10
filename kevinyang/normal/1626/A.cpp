#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		vector<int>freq(26);
		for(int i = 0; i<s.size(); i++){
			freq[s[i]-'a']++;
		}
		vector<char>a;
		vector<char>b;
		for(int i = 0; i<26; i++){
			if(freq[i]==2){
				a.push_back((char)('a'+i));
			}
			if(freq[i]==1){
				b.push_back((char)('a'+i));
			}
		}
		for(char nxt: a){
			cout << nxt;
		}
		for(char nxt: b){
			cout << nxt;
		}
		for(char nxt: a){
			cout << nxt;
		}
		cout << "\n";
	}
	return 0;
}