#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m,a,b,c,d;
		cin >> n >> m >> a >> b >> c >> d;
		int ans = 0;
		if(a==c||b==d){
			cout << "0\n";
			continue;
		}
		if(a<c)ans = c-a;
		else ans = n-c+n-a;
		if(b<d)ans = min(ans,d-b);
		else ans = min(ans,m-d+m-b);
		cout << ans << "\n";
	}
	return 0;
}