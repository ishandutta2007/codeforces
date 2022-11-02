#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

long long s[200009], d[200009], ts[200009], md = 1000000007;
map<long long, int> mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		mp.clear();
		int n; cin >> n;
		s[0] = 0;
		int c = 0;
		for (int i = 1; i <= n; i++) {
			int b; cin >> b;
			s[i] = s[i - 1] + b;
			if (mp.find(s[i]) == mp.end()) {
				c++;
				mp[s[i]] = c;
			}
			ts[i] = 0;
		}
		ts[n + 1] = 0;
		if (mp.find(0) == mp.end()) {
			c++;
			mp[0] = c;
		}
		ts[mp[0]] = 1;
		for (int i = 0; i <= n; i++)
			s[i] = mp[s[i]];
		long long ans = 1;
		for (int i = 1; i <= n; i++) {
			d[i] = (ans - ts[s[i - 1]] + md) % md;
			ts[s[i - 1]] = (ts[s[i - 1]] + d[i]) % md;
			ans = (ans + d[i]) % md;
		}
		cout << ans << '\n';
	}
	return 0;
}