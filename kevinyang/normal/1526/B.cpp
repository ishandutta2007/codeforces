#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		while(x>=111&&x%11!=0){
			x-=111;
		}
		if(x%11==0&&x>=0){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}