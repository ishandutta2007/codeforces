#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		vector<int>a(3);
		cin >> a[0] >> a[1] >> a[2];
		sort(a.begin(),a.end());
		if(a[0]+a[1]==a[2]){
			cout << "YES\n";
		}
		else if(a[0]==a[1]&&a[2]%2==0){
			cout << "YES\n";
		}
		else if(a[1]==a[2]&&a[0]%2==0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}