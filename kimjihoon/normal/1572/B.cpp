#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[200009], r[200009];
vector<int> ans;

void cc(int p)
{
	p -= 2;
	while (p >= 1 && a[p]) {
		ans.push_back(p);
		a[p] = a[p + 1] = 0;
		p -= 2;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		ans.clear();
		int n; cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];
		int c = 0, c1 = 0;
		for (int i = 1; i <= n; i++) {
			c++;
			if (i == n || a[i] != a[i + 1]) {
				for (int j = i - c + 1; j <= i; j++)
					r[j] = c % 2;
				c = 0;
			}
			if (a[i]) c1++;
		}
		if (c1 & 1) {
			cout << "NO" << '\n';
			continue;
		}
		if (a[1]) {
			if (r[1]) {
				for (int i = 1; i <= n - 2; i++) {
					if (a[i] && !a[i + 1] && i % 2 == 0)
						break;
					if (a[i] && !a[i + 1] && a[i + 2]) {
						ans.push_back(i);
						a[i] = a[i + 2] = 0;
						break;
					}
					if (a[i] && !a[i + 1] && !a[i + 2]) {
						ans.push_back(i);
						a[i + 1] = a[i + 2] = 1;
					}
				}
			}
			int p = -1;
			for (int i = 1; i <= n; i++) {
				if (!a[i]) {
					p = i;
					break;
				}
			}
			if (p == -1) {
				cout << "NO" << '\n';
				continue;
			}
			cc(p);
		}
		c = 0;
		for (int i = 1; i <= n - 2; i++) {
			if (a[i])
				c++;
			else
				c = 0;
			if (!a[i] && a[i + 1] && a[i + 2]) {
				ans.push_back(i);
				a[i + 1] = a[i + 2] = 0;
			}
			else if (a[i] && !a[i + 1] && c % 2 == 0)
				cc(i + 1);
			else if (a[i] && !a[i + 1] && a[i + 2]) {
				ans.push_back(i);
				a[i] = a[i + 2] = 0;
				cc(i);
			}
			else if (a[i] && !a[i + 1] && !a[i + 2]) {
				ans.push_back(i);
				a[i + 1] = a[i + 2] = 1;
			}
		}
		for (int i = 1; i <= n - 2; i++) {
			if (a[i] + a[i + 1] + a[i + 2] > 0 && (a[i] ^ a[i + 1] ^ a[i + 2]) == 0) {
				ans.push_back(i);
				a[i] = a[i + 1] = a[i + 2] = 0;
			}
		}
		cout << "YES" << '\n';
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}