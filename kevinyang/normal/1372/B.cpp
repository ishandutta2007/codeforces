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
		bool f = true;
		int low = 0;
		for(int i = 2; i*i<=n; i++){
			if(n%i==0){
				low = i;
				f = false;
				break;
			}
		}
		if(f){
			cout << 1 << " " << n-1 << "\n";
		}
		else{
			cout << n/low << " " << n-n/low << "\n";
		}
	}
	return 0;
}