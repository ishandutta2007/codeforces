#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool f[100009];
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
			f[i] = false;
		v.clear();
		int ans = n;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			if (a <= n && !f[a]) {
				f[a] = true;
				ans--;
			}
			else
				v.push_back(a);
		}
		if (!v.empty()) {
			sort(v.begin(), v.end()); 
			reverse(v.begin(), v.end());
		}
		int pi = n;
		bool ff = true;
		for (int i = 0; i < v.size(); i++) {
			while (pi >= 1 && f[pi])
				pi--;
			if (!pi) break;
			if (pi > (v[i] - 1) / 2) {
				ff = false;
				break;
			}
			pi--;
		}
		if (ff) cout << ans << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}