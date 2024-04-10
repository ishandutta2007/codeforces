#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,x,y;
		cin >> n >> x >> y;
		int w,b;
		cin >> w >> b;
		if(w<=(x+y)/2&&b<=(2*n-x-y)/2){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}