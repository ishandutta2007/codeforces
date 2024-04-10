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
		int k = n;
		int cnt = 0;
		while(k%2==0){
			cnt++;
			k/=2;
		}
		int v = n/k;
		v*=2;
		if(v<=(int)2e9&&v*(v+1)/2<=n){
			cout << v << "\n";
		}
		else{
			if(k==1){
				cout << "-1\n";
			}
			else{
				assert(k*(k+1)/2<=n);
				cout << k << "\n";	
			}
		}
	}
	return 0;
}