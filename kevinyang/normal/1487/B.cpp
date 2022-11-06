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
		if(n%2==0){
			if(k%n>0)
				cout << k%n << "\n";
			else
				cout << k%n+n << "\n";
		}
		else{
			int extra = (k-1)/(n/2);
			if((k+extra)%n==0)
				cout << (k+extra)%n+n << "\n";
			else{
				cout << (k+extra)%n << "\n";
			}
		}
	}
	return 0;
}