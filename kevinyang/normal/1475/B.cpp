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
		int v = n/2020;
		if(n%2020>v){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	return 0;
}