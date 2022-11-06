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
		bool f = true;
		int n = s.size();
		if(s[0]=='B')f = false;
		if(s[n-1]=='A')f = false;
		int cur = 0;
		for(int i = 0; i<n; i++){
			if(s[i]=='A')cur++;
			else cur--;
			if(cur<0)f = false;
		}
		cout << (f?"YES":"NO") << "\n";
	}
	return 0;
}