#include<iostream>
#include<vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MX = 1e5 + 13;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> res(MX);
	for (int i = 0; i < n; i++) {
		for(int j = 1; j <= int(sqrt(a[i]) + 1e-6); j++)
			if (a[i] % j == 0) {
				res[j]++;
				if(j * 1ll * j != a[i])
					res[a[i] / j]++;
			}
	}
	int ans = 1;
	for (int i = 2; i < MX; i++)
		ans = max(ans, res[i]);
	cout << ans;
	return 0;
}