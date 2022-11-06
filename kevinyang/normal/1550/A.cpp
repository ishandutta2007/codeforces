#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int s;
		cin >> s;
		int v = 0;
		int ans = 0;
		for(int i = 1; i<=5000; i+=2){
			ans++;
			s-=i;
			if(s<=0)break;
		}
		cout << ans << "\n";
	}
	return 0;
}