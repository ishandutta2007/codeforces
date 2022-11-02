#include <iostream>
using namespace std;

int a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, l;
	cin >> n >> m >> l;
	int s = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > l && a[i - 1] <= l)
			s++;
	}
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 0)
			cout << s << '\n';
		else {
			int p, d;
			cin >> p >> d;
			if (a[p] > l) continue;
			a[p] += d;
			if (a[p] > l) {
				if (a[p - 1] <= l && a[p + 1] <= l) s++;
				else if (a[p - 1] > l && a[p + 1] > l) s--;
			}
		}
	}
	return 0;
}