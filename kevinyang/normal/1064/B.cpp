#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a;
		cin >> a;
		int count = __builtin_popcount(a);
		cout << (int)pow(2,count) << "\n";
	}
	return 0;
}