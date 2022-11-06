#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		int dif = abs(a-b);
		dif*=2;
		if(a>dif||b>dif||c>dif){
			cout << "-1\n";
		}
		else{
			c+=dif/2;
			c%=dif;
			if(c==0)c = dif;
			cout << c << "\n";
		}
	}
	return 0;
}