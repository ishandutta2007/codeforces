#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a;
		cin >> a;
		cout << "Division ";
		if(a<=1399){
			cout << "4\n";
		}
		else if(a<=1599){
			cout << "3\n";
		}
		else if(a<=1899){
			cout << "2\n";
		}
		else{
			cout << "1\n";
		}
	}
	return 0;
}