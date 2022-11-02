#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[400009];
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, p; cin >> n >> p; p *= 8;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int c = 0;
	v.push_back(0);
	for (int i = 1; i <= n; i++) {
		c++;
		if (i == n || a[i] != a[i + 1]) {
			v.push_back(c + v.back());
			c = 0;
		}
	}
	int k = p / n;
	if (k > 30) k = (int)v.size() - 1;
	else k = min((int)v.size() - 1, (1 << k));
	int ans = 0;
	for (int i = k; i < v.size(); i++)
		ans = max(ans, v[i] - v[i - k]);
	cout << n - ans << '\n';
	return 0;
}