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
		if(x<=y){
			if(x*2>=y){
				cout << (x+y)/2 << "\n";
			}
			else{
				int v = y%x;
				v/=2;
				cout << y-v << "\n";
			}
		}
		else{
			cout << x+y << "\n";
		}
	}
	return 0;
}