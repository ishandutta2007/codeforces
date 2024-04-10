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
		if(n==2||n%2==1){
			cout << "-1\n";
		}
		else{
			int v = n/6;
			if(n%6!=0)v++;
			cout << v << " " << n/4 << "\n";
		}
	}
	return 0;
}