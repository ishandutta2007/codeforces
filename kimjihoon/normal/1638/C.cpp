#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[100009], l[100009], r[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			l[i] = max(l[i - 1], a[i]);
		}
		r[n] = a[n];
		for (int i = n - 1; i >= 1; i--)
			r[i] = min(r[i + 1], a[i]);
		int ans = 1;
		for (int i = 1; i < n; i++)
			if (l[i] < r[i + 1])
				ans++;
		cout << ans << '\n';
	}
	return 0;
}