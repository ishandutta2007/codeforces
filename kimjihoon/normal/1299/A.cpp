#include <iostream>
#include <algorithm>
using namespace std;

int a[100009], c[39], r[39];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int p = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j <= 30; j++)
			if (a[i] & (1 << j)) {
				c[j]++; r[j] = i;
			}
	}
	for (int i = 30; i >= 0; i--) {
		if (c[i] == 1) {
			p = r[i];
			break;
		}
	}
	cout << a[p] << " ";
	for (int i = 0; i < n; i++) {
		if (i == p) continue;
		cout << a[i] << " ";
	}
	cout << '\n';
	return 0;
}