#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[2009];
vector<int> v;

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		v.clear();
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] % 2 == 0) v.push_back(a[i]);
		}
		for (int i = 1; i <= n; i++) 
			if (a[i] % 2 == 1) 
				v.push_back(a[i]);
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (gcd(v[i], 2 * v[j]) > 1)
					ans++;
		cout << ans << '\n';
	}
	return 0;
}