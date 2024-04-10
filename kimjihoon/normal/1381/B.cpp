#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
bool d[4009], td[4009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int mx = 0, p = 1;
		v.clear();
		for (int i = 1; i <= 2 * n; i++) {
			int a; cin >> a;
			mx = max(mx, a);
			if (i > 1 && mx == a) {
				v.push_back(i - p);
				p = i;
			}
			d[i] = false;
		}
		v.push_back(2 * n - p + 1);
		d[0] = true;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j <= n; j++) {
				td[j] = false;
				if (d[j]) td[j] = true;
				else if (j - v[i] >= 0 && d[j - v[i]]) td[j] = true;
			}
			for (int j = 0; j <= n; j++)
				d[j] = td[j];
		}
		if (d[n]) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}