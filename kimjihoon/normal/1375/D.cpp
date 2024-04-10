#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[1009], c[1009];
bool p[1009];
vector<int> ans;

int cmex()
{
	for (int i = 0; i <= n; i++)
		if (!c[i])
			return i;
}

int rp()
{
	for (int i = 0; i < n; i++)
		if (!p[i])
			return i;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		cin >> n;
		int pc = 0;
		ans.clear();
		for (int i = 0; i <= n; i++) {
			c[i] = 0;
			p[i] = false;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == i) {
				p[i] = true;
				pc++;
			}
			c[a[i]]++;
		}
		while (pc < n) {
			int t = cmex();
			if (t == n) {
				int tp = rp();
				ans.push_back(tp + 1);
				c[n]++; c[a[tp]]--;
				a[tp] = n;
			}
			else {
				ans.push_back(t + 1);
				c[a[t]]--; c[t]++;
				a[t] = t;
				p[t] = true; pc++;
			}
		}
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}