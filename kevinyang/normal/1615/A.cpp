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
		int sum = 0;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			sum+=x;
		}
		if(sum%n==0){
			cout << "0\n";
		}
		else{
			cout << "1\n";
		}
	}
	return 0;
}