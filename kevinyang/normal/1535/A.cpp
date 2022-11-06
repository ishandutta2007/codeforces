#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		vector<int>arr(4);
		arr[0] = a; arr[1] = b; arr[2] = c; arr[3] = d;
		sort(arr.begin(),arr.end());
		int x = max(a,b); int y = max(c,d);
		if(max(x,y)==arr[3]&&min(x,y)==arr[2])cout << "YES\n";
		else cout << "NO\n";
	}	
	return 0;
}