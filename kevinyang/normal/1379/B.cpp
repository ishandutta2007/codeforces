#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int l,r,m;
		cin >> l >> r >> m;
		int change = r-l;
		for(int i = l; i<=r; i++){
			int mul = m/i*i;
			if(mul>0)
			if(m-mul<=change){
				cout << i << " " << l+m-mul << " " << l << "\n";
				break;
			}
			if(mul+i-m<=change){
				cout << i << " " << l << " " << l+mul+i-m << "\n";
				break;
			}
		}
	}
	return 0;
}