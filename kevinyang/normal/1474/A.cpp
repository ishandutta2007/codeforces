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
		int prev = 0;
		for(int i = 0; i<n; i++){
			if(s[i]-'0'+1!=prev){
				cout << 1;
				prev = s[i]-'0'+1;
			}
			else{
				prev = s[i]-'0';
				cout << 0;
			}
		}
		cout << "\n";
	}
	return 0;
}