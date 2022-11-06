#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m,x;
		cin >> n >> m >> x;
		int col = (x-1)/n + 1;
		int row = x%n;
		if(row==0)row = n;
		cout << (row-1)*m + col << "\n";
	}
	return 0;
}