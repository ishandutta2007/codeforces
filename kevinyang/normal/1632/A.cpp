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
		if(n==1||s=="01"||s=="10"){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}