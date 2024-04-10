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
		if(k>n){
			cout << k-n << "\n";
		}
		else{
			if((n-k)%2==0){
				cout << "0\n";
			}
			else{
				cout << "1\n";
			}
		}
	}
	return 0;
}