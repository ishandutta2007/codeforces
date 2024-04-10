#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p[100009];
bool vs[100009];
vector<int> ans;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;	
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
			vs[i] = false;
		}
		ans.clear();
		int t = n, r = n;
		for (int i = n; i >= 1; i--) {
			vs[p[i]] = true;
			if (p[i] == t) {
				for (int j = i; j <= r; j++) ans.push_back(p[j]);
				r = i - 1;
				while (vs[t]) t--;
			}
		}
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}