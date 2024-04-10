#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	int ans = 0;
	int tmp = 0;
	for(int i = n - 1;i > -1;i--){
		tmp += a[i] / 2;
		a[i] -= (a[i] / 2) * 2;
		if (tmp > 0){
			tmp -= a[i];
			ans += a[i];
		}
	}
	cout << ans + (tmp * 2) / 3;
}