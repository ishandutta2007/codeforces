#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int a[2009], p[2009];
map<int, int> mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int c = 0, r = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (mp.find(a[i]) != mp.end()) a[i] = mp[a[i]];
		else { mp[a[i]] = ++c; a[i] = c; }
		p[a[i]]++;
		if (p[a[i]] == 2) r++;
	}
	if (r == 0) {
		cout << 0 << '\n';
		return 0;
	}
	int ans = n;
	for (int i = 1; i <= n; i++) {
		int t = n;
		for (int j = i; j <= n; j++) {
			p[a[j]]--;
			if (p[a[j]] == 1) r--;
			if (r <= 0) {
				ans = min(ans, j - i + 1); t = j;
				break;
			}
		}
		for (int j = i; j <= t; j++) {
			p[a[j]]++;
			if (p[a[j]] == 2) r++;
		}
	}
	cout << ans << '\n';
	return 0;
}