#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int c[29];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		for (int j = 0; j < 20; j++)
			if (a & (1 << j))
				c[j]++;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long s = 0;
		for (int j = 0; j < 20; j++) {
			if (c[j]) {
				s += (1 << j);
				c[j]--;
			}
		}
		ans += s * s;
	}
	cout << ans << '\n';
	return 0;
}