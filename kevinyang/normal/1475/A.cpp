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
		while(n%2==0){
			n/=2;
		}
		if(n==1){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	return 0;
}