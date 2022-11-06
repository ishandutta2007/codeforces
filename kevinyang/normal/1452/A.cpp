#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x,y;
		cin >> x >> y;
		if(y>x)swap(x,y);
		int ans = y*2;
		x-=y;
		y = 0;
		if(x>0){
			x--;
			ans++;
		}
		if(x>0){
			ans+=x*2;
		}
		cout << ans << "\n";
	}
	return 0;
}