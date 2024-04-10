#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		k = (n-1)/k*k+k;
		if(k%n==0){
			cout << k/n << "\n";
		}
		else{
			cout << k/n+1 << "\n";
		}
	}
	return 0;
}