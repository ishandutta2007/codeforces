#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[100009];
bool vs[200009];
vector<int> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	for (int i = 2; i <= mx; i++) {
		if (vs[i]) continue;
		p.push_back(i);
		for (int j = i; j <= mx; j += i)
			vs[j] = true;
	}
	long long ans = 1;
	for (int i = 0; i < p.size(); i++) {
		int mn0 = 1000000000, mn1 = 1000000000, rc = 0;
		for (int j = 0; j < n; j++) {
			if (a[j] % p[i] == 0) {
				int c = 0;
				while (a[j] % p[i] == 0) {
					a[j] /= p[i];
					c++;
				}
				if (mn0 > c) {
					mn1 = mn0;
					mn0 = c;
				}
				else if (mn1 > c)
					mn1 = c;
			}
			else
				rc++;
			if (rc >= 2) break;
		}
		if (rc >= 2) continue;
		if (rc == 1 || mn1 == 1000000000)
			for (int j = 0; j < mn0; j++)
				ans *= 1LL * p[i];
		else
			for (int j = 0; j < mn1; j++)
				ans *= 1LL * p[i];
	}
	cout << ans << '\n';
	return 0;
}