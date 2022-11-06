#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n >> x;
		if(x==1){
			cout << max(1LL,n-1) << "\n";
			continue;
		}
		if(x==2){
			cout << (n+1)/2 << "\n";
			continue;
		}
		n+=x-2;
		cout << (n+x-1)/x << "\n";
	}
	return 0;
}