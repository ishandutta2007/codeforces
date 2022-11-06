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
		int ans = 0;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			x--;
			ans+=x;
		}
		if(ans%2==0){
			cout << "maomao90\n";
		}
		else{
			cout << "errorgorn\n";
		}
	}
	return 0;
}