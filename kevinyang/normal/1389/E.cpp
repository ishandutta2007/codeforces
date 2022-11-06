#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int m,d,w;
		int ans = 0;
		cin >> m >> d >> w;
		int w2 = w/gcd(d-1,w);
		int mn = min(m,d);
		int end = mn/w2;
		ans = 2*mn-2*w2-w2*(end-1);
		ans*=end;
		ans/=2;

		cout << ans << "\n";
	}
	return 0;
}