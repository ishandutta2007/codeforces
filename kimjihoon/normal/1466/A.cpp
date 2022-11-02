#include <iostream>
#include <algorithm>
using namespace std;

int a[109];
bool vs[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) 
			cin >> a[i];
		for (int i = 0; i <= 100; i++)
			vs[i] = false;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				vs[a[j] - a[i]] = true;
		int ans = 0;
		for (int i = 1; i <= 100; i++)
			if (vs[i])
				ans++;
		cout << ans << '\n';
	}
	return 0;
}