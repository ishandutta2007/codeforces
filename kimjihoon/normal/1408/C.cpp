#include <iostream>
#include <algorithm>
using namespace std;

int a[100009];
double s1[100009], s2[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, l; cin >> n >> l;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		a[0] = 0; a[n + 1] = l;
		s1[0] = 0;
		for (int i = 1; i <= n + 1; i++) {
			s1[i] = s1[i - 1] + (double)(a[i] - a[i - 1]) / (double)i;
		}
		s2[n + 1] = 0;
		for (int i = n; i >= 0; i--) {
			s2[i] = s2[i + 1] + (double)(a[i + 1] - a[i]) / (double)(n + 1 - i);
		}
		double ans = 0;
		for (int i = 1; i <= n + 1; i++) {
			if (s2[i] <= s1[i]) {	
				double v1 = i, v2 = n + 2 - i;
				ans = ((double)(a[i] - a[i - 1]) + (s2[i] - s1[i - 1]) * v2) / (v1 + v2) + s1[i - 1];
				break;
			}
		}
		cout.setf(ios::fixed);
		cout.precision(20);
		cout << ans << '\n';
	}
	return 0;
}