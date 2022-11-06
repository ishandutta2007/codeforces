#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<int>a;
	if(true){
		int cur = 1;
		for(int i = 0; i<12; i++){
			a.push_back(cur);
			cur*=10;
		}
	}
	int t;
	cin >> t;
	while(t--){
		int m;
		cin >> m;
		int v = *--upper_bound(a.begin(),a.end(),m);
		cout << m-v << "\n";
	}
	return 0;
}