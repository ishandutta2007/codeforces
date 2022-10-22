#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, x;
	cin >> n >> x;
	int ans = 0, tmp = 0, sum = 0, z = 0, tmp1 = 0;
	for(int i = 0;i < n;i++){
		int a;
		cin >> a;
		sum = max(sum + a, z);
		tmp = max(sum, tmp + a * x );
		tmp1 = max(tmp, tmp1 + a);
		ans = max(ans, tmp1);
	}
	cout << ans;
	
	return 0;
}