#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		if(n>m){
			cout << "0\n";
		}
		else{
			m++;
			int ans = 0;
			for(int i = 30; i>=0; i--){
				if(m&(1<<i)){
					if(n&(1<<i))continue;
					else ans+=(1<<i);
				}
				if(n&(1<<i))break;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}