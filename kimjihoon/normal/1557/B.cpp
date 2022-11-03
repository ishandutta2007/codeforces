#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int a[100009], b[100009];
map<int, int> mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b, b + n);
		for (int i = 0; i < n; i++)
			mp[b[i]] = i;
		int s = 0;
		for (int i = 0; i < n; i++) {
			a[i] = mp[a[i]];
			if (i && a[i - 1] != a[i] - 1)
				s++;
		}
		if (k >= s + 1) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}