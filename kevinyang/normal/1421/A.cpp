#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		int v = a&b;
		cout << (a^v) + (b^v) << "\n";
	}
	return 0;
}