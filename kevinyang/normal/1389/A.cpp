#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		if(a*2<=b){
			cout << a << " " << a*2 << "\n";
		}
		else{
			cout << "-1 -1\n";
		}
	}
	return 0;
}