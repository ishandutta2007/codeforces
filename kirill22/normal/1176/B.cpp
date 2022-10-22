#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		int a = 0,b = 0,c = 0;
		for(int i = 0;i < n;i++){
			int x;
			cin >> x;
			if(x % 3 == 0){
				a++;
			}
			if(x % 3 == 1){
				b++;
			}
			if(x % 3 == 2){
				c++;
			}
			
		}
		int ans = a;
		if(b >= c){
			ans += c + (b - c) / 3;
		}
		else{
			ans += b + (c - b) / 3;
		}
		cout << ans << endl;
	}
}