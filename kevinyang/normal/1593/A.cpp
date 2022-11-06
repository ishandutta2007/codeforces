#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		cout << max({a,b+1,c+1})-a << " ";
		cout << max({a+1,b,c+1})-b << " ";
		cout << max({a+1,b+1,c})-c ;
		cout << "\n";
	}
	return 0;
}