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
		if(count(s.begin(),s.end(),'N')==1){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	return 0;
}