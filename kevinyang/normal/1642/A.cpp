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
		int ans = 0;
		if(b==d&&b!=0&&b>f){
			ans+=abs(c-a);
		}
		if(b==f&&b!=0&&b>d){
			ans+=abs(e-a);
		}
		if(d==f&&f!=0&&f>b){
			ans+=abs(e-c);
		}
		cout << ans << "\n";
	}
	return 0;
}