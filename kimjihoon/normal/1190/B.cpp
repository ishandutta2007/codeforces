#include <iostream>
#include <algorithm>
using namespace std;

int a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n == 1) {
		if (a[0] % 2) cout << "sjfnb" << '\n';
		else cout << "cslnb" << '\n';
		return 0;
	}
	sort(a, a + n);
	int c = 0, ci = 0;
	for (int i = 0; i < n - 1; i++)
		if (a[i] == a[i + 1]) {
			c++; ci = i;
		}
	if (c > 1 || (c == 1 && a[ci] == 0) || (ci > 0 && a[ci - 1] + 1 == a[ci])) {
		cout << "cslnb" << '\n';
		return 0;
	}
	long long t = 0;
	for (int i = 0; i < n; i++) 
		t += a[i] - 1LL * i;
	if (t % 2LL) cout << "sjfnb" << '\n';
	else cout << "cslnb" << '\n';
	return 0;
}