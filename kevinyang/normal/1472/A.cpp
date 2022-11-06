#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int w,h,n;
		cin >> w >> h >> n;
		int ans = 1;
		while(w%2==0){
			ans*=2; w/=2;
		}
		while(h%2==0){
			ans*=2; h/=2;
		}
		if(ans>=n){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}