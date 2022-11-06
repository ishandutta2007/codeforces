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
		for(int i = 0; i<n-1; i++){
			if(s[i]!=s[i+1]){
				cout << i+1 << " " << i+2 << "\n";
				f = true;
				break;
			}
		}
		if(!f){
			cout << "-1 -1\n";
		}
	}
	return 0;
}