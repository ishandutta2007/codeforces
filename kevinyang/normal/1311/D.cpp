#include <bits/stdc++.h>
using namespace std;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		int ans = 1e18;
		vector<int>arr(3);
		for(int i = 1; i<=20000; i++){
			int val = i/a;
			int a1 = 1; int mn1 = 1e18;
			for(int j = 1; j*j<=i; j++){
				if(i%j==0){
					if(abs(a-j)<mn1){
						a1 = j;
						mn1 = abs(a-j);
					}
					if(abs(a-i/j)<mn1){
						a1 = i/j;
						mn1 = abs(a-i/j);
					}
				}
			}
			val = c/i;
			int a2;
			if(abs(c-i*val)<abs(c-i*(val+1))){
				a2 = i*val;
			}
			else{
				a2 = i*(val+1);
			}
			int mn2 = min(abs(c-i*val),abs(c-i*(val+1)));
			if(mn1+mn2+abs(b-i)<ans){
				arr[0] = a1; arr[1] = i; arr[2] = a2;
			}
			ans = min(ans,mn1+mn2+abs(b-i));
		}
		cout << ans << "\n";
		cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
	}
	return 0;
}