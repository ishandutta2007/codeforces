#include <iostream>
#include <algorithm>
using namespace std;

void ps(int n, int c)
{
	if (c <= 0) return;
	if (c == 1) {
		cout << n << " ";
		return;
	}
	ps(n / 2, c / 2), ps(n / 2, (c + 1) / 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	int tn = n, c = 0;
	while (tn) {
		c += (tn % 2);
		tn /= 2;
	}
	if (n < k || k < c) {
		cout << "NO" << '\n';
		return 0;
	}
	cout << "YES" << '\n';
	tn = n; int t = 1;
	while (tn) {
		if (tn % 2) {
			int r = min(k - c + 1, t);
			k -= r - 1;
			ps(t, r);
		}
		tn /= 2; t *= 2;
	}
	cout << '\n';
	return 0;
}