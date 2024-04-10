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
		int n = s.length();
		bool f = false;
		for(int i = -1; i<=n; i++){
			bool flag = true;
			if(true){
				int prev = -5;
				for(int j = 0; j<i; j++){
					if(s[j]=='1'){
						if(prev+1==j)flag = false;
						prev = j;
					}
				}
			}
			if(true){
				int prev = -5; 
				for(int j = i+1; j<n; j++){
					if(s[j]=='0'){
						if(prev+1==j)flag = false;
						prev = j;
					}
				}
			}
			if(flag)f = true;
		}
		if(f){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}