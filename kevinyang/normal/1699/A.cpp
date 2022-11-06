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
		if(n%2==1)cout << "-1\n";
		else cout << n/2 << " " << n/2 << " 0\n";
	}
	return 0;
}