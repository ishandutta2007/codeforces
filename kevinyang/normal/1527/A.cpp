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
		int cur = n;
		int mn = 0;
		for(int i = 30; i>=0; i--){
			if(n&(1<<i)){
				int wait = n%(1<<i);
				wait++;
				mn = max(mn,wait);
			}
		}
		cout << n-mn << "\n";
	}
	return 0;
}