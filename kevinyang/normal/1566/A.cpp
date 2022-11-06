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
		int k = n-(n-1)/2;
		cout << s/k << "\n";
	}
	return 0;
}