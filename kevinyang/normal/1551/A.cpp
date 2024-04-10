#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int v = n/3; int v2 = n/3;
		if(n%3==1)v++;
		else if(n%3==2)v2++;
		cout << v << " " << v2 << "\n";
	}
	return 0;
}