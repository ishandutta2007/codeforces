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
		char ch;
		cin >> ch;
		int n = s.size();
		bool f = false;
		for(int i = 0; i<n; i+=2){
			if(s[i]==ch){
				f = true;
			}
		}
		cout << (f?"YES":"NO") << "\n";
	}
	return 0;
}