#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	if(n % 2 == 1){
		cout << 0;
		return 0;
	}
	int ans = 1;
	while(n > 0){
		ans *= 2;
		n -= 2;
	}
	cout << ans;
	
}