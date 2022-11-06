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
		if(n%2==1){
			cout << "1 " << n/2 << " " << n/2 << "\n";
		}
		else{
			if(n%4==2){
				n-=2;
				cout << "2 " << n/2 << " " << n/2 << "\n";
			}
			else{
				cout << n/4 << " " << n/4 << " " << n/2 << "\n";
			}
		}
	}
	return 0;
}