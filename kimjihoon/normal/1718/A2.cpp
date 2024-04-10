#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> mp;
int d[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int s = 0;
		mp.clear();
		mp[0] = 0; d[0] = 0;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			s ^= a;
			d[i] = d[i - 1] + 1;
			if (mp.find(s) != mp.end()) {
				int t = mp[s];
				d[i] = min(d[i], t + i - 1);
				mp[s] = min(t, d[i] - i);
			}
			else
				mp[s] = d[i] - i;
		}
		cout << d[n] << '\n';
	}
	return 0;
}