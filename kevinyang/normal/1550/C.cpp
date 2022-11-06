#include <bits/stdc++.h>
using namespace std;
#define int long long
bool good3(int a, int b, int c){
	if(a<=b&&b<=c)return true;
	if(a>=b&&b>=c)return true;
	return false;
}
bool good4(int a, int b, int c, int d){
	if(good3(a,b,c)||good3(a,b,d)||good3(a,c,d)||good3(b,c,d))return true;
	return false;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		int ans = 2*n-1;
		for(int i = 3; i<=n; i++){
			if(!good3(arr[i-2],arr[i-1],arr[i]))ans++;
		}
		for(int i = 4; i<=n; i++){
			if(!good4(arr[i-3],arr[i-2],arr[i-1],arr[i]))ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}