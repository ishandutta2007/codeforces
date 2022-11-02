#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int a[1009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 1000000000, ai = 0;
	for (int i = 1; i <= 100; i++) {
		int s = 0;
		for (int j = 0; j < n; j++)
			s += max(abs(i - a[j]) - 1, 0);
		if (s < ans) {
			ans = s; ai = i;
		}
	}
	cout << ai << " " << ans << '\n';
	return 0;
}