#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int p,a,b,c;
		cin >> p >> a >> b >> c;
		int ans = (int)9e18;
		ans = min(ans,(a-p%a)%a);
		ans = min(ans,(b-p%b)%b);
		ans = min(ans,(c-p%c)%c);
		cout << ans << "\n";
	}
	return 0;
}