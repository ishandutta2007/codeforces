#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,s;
		cin >> n >> s;
		cout << s/(n*n) << "\n";
	}
	return 0;
}