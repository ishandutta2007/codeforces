#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int a,b,c;
	cin >> a >> b >> c;
	int ans = 2*c;
	int mn = min(a,b);
	ans+=2*mn;
	a-=mn; b-=mn;
	if(a>0||b>0)ans++;
	cout << ans << "\n";
	return 0;
}