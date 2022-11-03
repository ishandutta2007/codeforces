#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a, b;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int ans = 0;
		for (int i = 0; i <= 6; i++) {
			int t = (1 << i);
			a.clear(); b.clear();
			for (int j = 1; j <= n; j++) {
				if (j & t) a.push_back(j);
				else b.push_back(j);
			}
			if (a.size() == 0 || b.size() == 0) continue;
			cout << a.size() << " " << b.size() << " ";
			for (int j = 0; j < a.size(); j++) cout << a[j] << " ";
			for (int j = 0; j < b.size(); j++) cout << b[j] << " ";
			cout << endl;
			int p; cin >> p;
			ans = max(p, ans);
		}
		cout << -1 << " " << ans << endl;
	}
	return 0;
}