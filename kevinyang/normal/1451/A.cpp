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
		if(n<=3){
			cout << n-1 << "\n";
		}
		else if(n%2==1){
			cout << "3\n";
		}
		else{
			cout << 2 << "\n";
		}
	}
	return 0;
}