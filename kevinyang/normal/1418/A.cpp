#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x,y,k;
		cin >> x >> y >> k;
		int rq = k*(y+1)-1;
		int ans = (rq)/(x-1);
		if(rq%(x-1)>0)ans++;
		cout << ans+k << "\n";
	}
	return 0;
}