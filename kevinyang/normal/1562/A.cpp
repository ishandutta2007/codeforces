#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int l,r;
		cin >> l >> r;
		int v = r/2+1;
		if(v>=l){
			cout << r%v << "\n";
		}
		else{
			cout << r%l << "\n";
		}
	}
	return 0;
}