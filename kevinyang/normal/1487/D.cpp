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
		int mx = 2*n-1;
		cout << ((int)sqrt(mx)-1)/2 << "\n";
	}
	return 0;
}