#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[300009];
bool vs[1009];
vector<int> pr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i <= 1000; i++) {
		if (vs[i]) continue;
		for (int j = i; j <= 1000; j += i)
			vs[j] = true;
		pr.push_back(i * i);
	}
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < pr.size() && pr[j] <= a[i]; j++)
				if (a[i] % pr[j] == 0) {
					a[i] /= pr[j]; j--;
				}
		}
		sort(a, a + n);
		int c = 0, mx = 0, s = 0;
		for (int i = 0; i < n; i++) {
			c++;
			if (i == n - 1 || a[i] != a[i + 1]) {
				mx = max(mx, c);
				if (a[i] == 1 || c % 2 == 0) s += c;
				c = 0;
			}
		}
		s = max(s, mx);
		int q; cin >> q;
		for (int i = 0; i < q; i++) {
			long long w; cin >> w;
			if (!w) cout << mx << '\n';
			else cout << s << '\n';
		}
	}
	return 0;
}