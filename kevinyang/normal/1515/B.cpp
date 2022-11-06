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
		if(n==1){
			cout << "NO\n";
			continue;
		}
		bool f = false;

		if(n%2==0&&(int)sqrt(n/2)*(int)sqrt(n/2)==n/2)f = true;
		if(n%4==0&&(int)sqrt(n/4)*(int)sqrt(n/4)==n/4)f = true;
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}