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
		bool f = false;
		for(int i = 0; i<26; i++){
			if(f)break;
			bool flag = true;
			for(int j = 0; j<n; j++){
				if(s[j]=='a'+i){
					flag = false;
					break;
				}
			}
			if(flag){
				cout << (char)('a'+i) << "\n";
				f = true;
				break;
			}
		}
		for(int a = 0; a<26; a++){
			if(f)break;
			for(int b = 0; b<26; b++){
				if(f)break;
				bool flag = true;
				for(int j = 0; j<n-1; j++){
					if(s[j]=='a'+a&&s[j+1]=='a'+b){
						flag = false;
						break;
					}
				}
				if(flag){
					f = true;
					cout << (char)('a'+a) << (char)('a'+b) << "\n";
					break;
				}
			}
		}
		for(int a = 0; a<26; a++){
			if(f)break;
			for(int b = 0; b<26; b++){
				if(f)break;
				for(int c = 0; c<26; c++){
					if(f)break;
					bool flag = true;
					for(int j = 0; j<n-2; j++){
						if(s[j]=='a'+a&&s[j+1]=='a'+b&&s[j+2]=='a'+c){
							flag = false;
							break;
						}
					}
					if(flag){
						f = true;
						cout << (char)('a'+a) << (char)('a'+b) << (char)('a'+c) << "\n";
						break;
					}
				}
				
			}
		}
	}
	return 0;
}