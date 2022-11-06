#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int w,h;
		cin >> w >> h;
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int n,m;
		cin >> n >> m;//width, then height
		int ans = (int)1e18;
		if(true){
			if(a<n&&b<m){
				if(c-a+n<=w)ans = min(ans,n-a);
				if(d-b+m<=h)ans = min(ans,m-b);
			}
			else{
				ans = 0;
			}
		}
		if(w-n<c&&b<m){
			if(c-a+n<=w)ans = min(ans,c-(w-n));
			if(d-b+m<=h)ans = min(ans,m-b);
		}
		else{
			ans = 0;
		}
		if(a<n&&h-m<d){
			if(c-a+n<=w)ans = min(ans,n-a);
			if(d-b+m<=h)ans = min(ans,d-(h-m));
		}
		else{
			ans = 0;
		}
		if(w-n<c&&h-m<d){
			if(c-a+n<=w)ans = min(ans,c-(w-n));
			if(d-b+m<=h)ans = min(ans,d-(h-m));
		}
		else{
			ans = 0;
		}
		if(ans==(int)1e18)cout << "-1\n";
		else cout << ans << "\n";
	}
	return 0;
}