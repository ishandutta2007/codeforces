#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int p;
		cin >> p;
		p--;
		if(p==4){
			cout << "2 4\n";
		}
		else{
			cout << "2 " << p/2 << "\n";
		}
	}
	return 0;
}