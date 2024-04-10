#include <iostream>
using namespace std;

int a[100009], d[100009];
bool vs[100009], vs1[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = n - 1; i >= 0; i--) {
		if (vs[a[i]])
			d[i] = d[i + 1];
		else {
			vs[a[i]] = true;
			d[i] = d[i + 1] + 1;
		}
	}
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (vs1[a[i]]) continue;
		vs1[a[i]] = true;
		ans += d[i + 1];
	}
	cout << ans << '\n';
	return 0;
}