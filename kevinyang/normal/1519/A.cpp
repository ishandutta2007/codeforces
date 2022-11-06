#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int r,b,d;
		cin >> r >> b >> d;
		if(r>b)swap(r,b);
		int dif = b-r;
		if(d*r<dif)cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}