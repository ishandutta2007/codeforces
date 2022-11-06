#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int s,n,k;
		cin >> s >> n >> k;
		if(s<k){
			cout << "NO\n";
			continue;
		}
		if(s==k){
			cout << "YES\n";
			continue;
		}
		if(k<=n){
			int rq = n/k*(k);
			if(rq+n<=s){
				cout << "NO\n";
			}
			else{
				cout << "YES\n";
			}
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}