#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,c,d,e,f;
		cin >> a >> b >> c >> d >> e >> f;
		int ans = abs(c-a)+abs(d-b);
		if(a==c&&c==e&&abs(b-d)==abs(f-d)+abs(f-b))ans+=2;
		if(b==d&&d==f&&abs(a-c)==abs(e-a)+abs(e-c))ans+=2;
		cout << ans << "\n";
	}
	return 0;
}