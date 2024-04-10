#include <iostream>
using namespace std;

int l[1009], r[1009], a[1009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i];
	for (int i = 0; i < n; i++)
		cin >> r[i];
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < n; j++) {
			if (a[j] != 0) continue;
			if (l[j] == 0 && r[j] == 0)
				a[j] = i;
		}
		int c = 0;
		for (int j = 0; j < n; j++) {
			if (a[j] == i) c++;
			else if (a[j] == 0) {
				l[j] -= c;
				if (l[j] < 0) {
					cout << "NO" << '\n';
					return 0;
				}
			}
		}
		c = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (a[j] == i) c++;
			else if (a[j] == 0) {
				r[j] -= c;
				if (r[j] < 0) {
					cout << "NO" << '\n';
					return 0;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (l[i] != 0 || r[i] != 0) {
			cout << "NO" << '\n';
			return 0;
		}
	cout << "YES" << '\n';
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << '\n';
	return 0;
}