#include <iostream>
using namespace std;

int a[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int mx = 0, mi = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (mx < a[i]) {
			mx = a[i];
			mi = i;
		}
	}
	for (int i = mi; i < n - 1; i++)
		if (a[i] < a[i + 1]) {
			cout << "NO" << '\n';
			return 0;
		}
	for (int i = mi; i > 0; i--)
		if (a[i] < a[i - 1]) {
			cout << "NO" << '\n';
			return 0;
		}
	cout << "YES" << '\n';
	return 0;
}