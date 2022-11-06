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
		if(b==1)cout << "NO\n";
		else{
			cout << "YES\n";
			int x = a*b;
			int y = x+a;
			cout << x << " " << y << " " << x+y << "\n";
		}
	}
	return 0;
}