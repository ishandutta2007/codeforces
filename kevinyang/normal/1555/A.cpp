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
		if(n<=6)cout << "15\n";
		else{
			if(n%2==1)n++;
			cout << n*5/2 << "\n";
		}
	}
	return 0;
}