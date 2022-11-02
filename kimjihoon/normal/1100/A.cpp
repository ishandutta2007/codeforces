#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int a[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	int ans = -1000000000;
	for (int i = 0; i < k; i++) {
		int e = 0, s = 0;
		for (int j = 0; j < n; j++) {
			if ((j - i) % k == 0) continue;
			if (a[j] == 1) e++;
			else s++;
		}
		ans = max(ans, abs(e - s));
	}
	cout << ans << '\n';
	return 0;
}