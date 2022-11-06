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
		if(s[0]-'a'>k){
			char low = s[0]-k;
			for(int i = 0; i<n; i++){
				if(s[i]>=low&&s[i]<=s[0]){
					cout << low;
				}
				else cout << s[i];
			}
			cout << "\n";
			continue;
		}
		char mx1 = ' ';
		char mx2 = ' ';
		for(int i = 0; i<n; i++){
			if(s[i]-'a'>k){
				mx2 = s[i];
				break;
			}
			else{
				mx1 = max(mx1,s[i]);
			}
		}
		vector<char>ans(n);
		if(mx2==' '){
			for(int i = 0; i<n; i++){
				cout << 'a';
			}
			cout << "\n";
		}
		else{
			int old = (mx1-'a');
			int add = k-old;
			char low = mx2-add;
			for(int i = 0; i<n; i++){
				if(s[i]<=mx1){
					cout << 'a';
				}
				else if(s[i]>=low&&s[i]<=mx2){
					cout << (char)(mx2-add);
				}
				else{
					cout << s[i];
				}
			}
			cout << "\n";
		}
	}
	return 0;
}