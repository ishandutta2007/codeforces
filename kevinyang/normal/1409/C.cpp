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
		int dif = 0;
		for(int i = n-1; i>=1; i--){
			if((y-x)%i==0){
				dif = (y-x)/i;
				break;
			}
		}
		if((y-1)/dif>=n-1){
			for(int i = n; i>0; i--){
				cout << y << " ";
				y-=dif;
			}
		}
		else{
			while(x>0)x-=dif;
			x+=dif;
			for(int i = 0; i<n; i++){
				cout << x << " ";
				x+=dif;
			}
		}
		cout << "\n";
	}
	return 0;
}