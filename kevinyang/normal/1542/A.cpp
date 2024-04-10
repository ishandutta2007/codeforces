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
		int cnt = 0;
		for(int i = 0; i<2*n; i++){
			int x;
			cin >> x;
			if(x%2==1)cnt++;
		}
		if(cnt==n){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}