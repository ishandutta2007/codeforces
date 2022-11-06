#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x,y;
		cin >> x >> y;
		if(y%x==0){
			cout << "1 " << y/x << "\n";
		}
		else{
			cout << "0 0\n";
		}
	}
	return 0;
}