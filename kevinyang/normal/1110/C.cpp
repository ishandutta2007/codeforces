#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		int x;
		cin >> x;
		int mx = 0;
		for(int i = 0; i<30; i++){
			if((1<<i)&x)mx = i;
		}
		if((1<<(mx+1))-1==x){
			int mx = 1;
			for(int i = 2; i*i<=x; i++){
				if(x%i==0){
					mx = max(mx,i);
					mx = max(mx,x/i);
				}
			}
			cout << mx << "\n";
		}
		else{
			cout << ((1<<(mx+1))-1) << "\n";
		}
	}
	return 0;
}