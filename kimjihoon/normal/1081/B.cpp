#include <iostream>
using namespace std;

int a[100009], r[100009], p[100009], bp[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i] = n - a[i];
		r[a[i]]++; p[i] = -1;
	}
	p[n] = -1;
	for (int i = 1; i <= n; i++)
		if (r[i] != 0 && (r[i] < i || r[i] % i != 0)) {
			cout << "Impossible" << '\n';
			return 0;
		}
	cout << "Possible" << '\n';
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (p[a[i]] == -1) {
			p[a[i]] = 1; c++;
			bp[a[i]] = c;
		}
		else if (p[a[i]] == a[i]) {
			p[a[i]] = 1; c++;
			bp[a[i]] = c;
		}
		else
			p[a[i]]++;
		cout << bp[a[i]] << " ";
	}
	cout << '\n';
	return 0;
}