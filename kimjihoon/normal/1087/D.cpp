#include <iostream>
using namespace std;

int c[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	int n, s; cin >> n >> s;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		c[a]++; c[b]++;
	}
	int rc = 0;
	for (int i = 1; i <= n; i++)
		if (c[i] == 1)
			rc++;
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << (double)(s * 2) / (double)rc << '\n';
	return 0;
}