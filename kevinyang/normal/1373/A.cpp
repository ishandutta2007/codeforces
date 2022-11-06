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
		if(a<c){
			cout << 1 << " ";
		}
		else{
			cout << -1 << " ";
		}
		int num = (int)1e9/b*c;
		if(num<(int)1e9/b*b*a){
			cout << (int)1e9/b*b << "\n";
		}
		else{
			cout << -1 << "\n";
		}
	}
	return 0;
}