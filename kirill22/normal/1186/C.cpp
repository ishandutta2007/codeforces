#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	string a, b;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();
	vector<int> c(n + 1, 0);
	for(int i =  1;i <= n;i++) {
		c[i] = c[i - 1];
		if(a[i - 1] == '1') {
			c[i]++;
		}
	}
	int x = 0;
	for(int i =  0;i < m ;i++) {
		if(b[i] == '1') {
			x++;
		}
	}
	int ans = 0;
	for(int i = m - 1;i < n;i++) {
		int y = c[i + 1] - c[i - m + 1];
		//cout << x << " " << y << endl;
		if((x - y) % 2 == 0) {
			ans++;
		}
	}
	cout << ans;
}