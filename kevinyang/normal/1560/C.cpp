#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		int ret = 0;
		for(int i = 0; i*i<k; i++){
			ret = i;
		}
		int x = ret+1; int y = 1;
		if(ret*ret+ret+1>=k){
			int dif = k-ret*ret-1;
			y+=dif;
			cout << y << " " << x << "\n";
		}
		else{
			y = ret+1;
			int dif = k-(ret*ret+ret+1);
			x-=dif;
			cout << y << " " << x << "\n";
		}
	}
	return 0;
}