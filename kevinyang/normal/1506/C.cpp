#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string a,b;
		cin >> a >> b;
		int ans = 0;
		for(int i = 0; i<a.length(); i++){
			for(int j = i; j<a.length(); j++){
				for(int k = 0; k+j-i<b.length(); k++){
					if(a.substr(i,j-i+1)==b.substr(k,j-i+1))ans = max(ans,j-i+1);
				}
			}
		}
		cout << a.length()+b.length()-2*ans << "\n";
	}
	return 0;
}