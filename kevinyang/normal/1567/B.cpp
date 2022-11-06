#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		int v = 0;
		for(int i = a/4*4; i<a; i++){
			v^=i;
		}
		if(v==b)cout << a << "\n";
		else if((v^b)==a)cout << a+2 << "\n";
		else cout << a+1 << "\n";
	}
	return 0;
}