#include <iostream>
#include <algorithm>
using namespace std;

int a[100009], p[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i - 1] = a[i] - a[i - 1] - 1;
	}
	int ans = a[n] - a[1] + 1;
	sort(p + 1, p + n); reverse(p + 1, p + n);
	for (int i = 1; i < n && i < k; i++)
		ans -= p[i];
	cout << ans << '\n';
	return 0;
}