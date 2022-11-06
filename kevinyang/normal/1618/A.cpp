#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		vector<int>a;
		for(int i = 0; i<7; i++){
			int x;
			cin >> x;
			a.push_back(x);
		}
		if(a[0]+a[1]==a[2]){
			cout << a[0] << " " << a[1] << " " << a[3] << "\n";
		}
		else{
			cout << a[0] << " " << a[1] << " " << a[2] << "\n";
		}
	}
	return 0;
}