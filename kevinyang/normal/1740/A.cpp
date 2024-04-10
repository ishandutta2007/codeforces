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
		if(n%2==0){
			cout << "2\n";
		}
		else{
			cout << "3\n";
		}
	}
	return 0;
}