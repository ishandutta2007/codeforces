#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,x,y,n;
		cin >> a >> b >> x >> y >> n;
		int ans = (int)1e18;
		if(true){
			int a1 = a; int b1 = b; int x1 = x; int y1 = y; int n1 = n;
			int min1 = min(a1-x1,n1);
			a1-=min1;
			n1-=min1;
			int min2 = min(b1-y1,n1);
			b1-=min2;
			ans = min(ans,a1*b1);
		}
		if(true){
			int min1 = min(b-y,n);
			b-=min1;n-=min1;
			int min2 = min(a-x,n);
			a-=min2;
			ans = min(ans,a*b);
		}
		cout << ans << "\n";
	}
	return 0;
}