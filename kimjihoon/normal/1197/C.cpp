#include <iostream>
#include <algorithm>
using namespace std;

int a[300009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	long long s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) {
			a[i - 1] = a[i] - a[i - 1];
			s += a[i - 1];
		}
	}
	sort(a, a + n - 1); reverse(a, a + n - 1);
	for (int i = 0; i < k - 1; i++)
		s -= a[i];
	cout << s << '\n';
	return 0;
}