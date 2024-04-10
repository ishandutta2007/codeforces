#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> ans[10009], st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		ans[0].clear(); st.clear();
		for (int i = 1; i <= n; i++) {
			ans[i].clear();
			int a; cin >> a;
			if (i == 1) {
				st.push_back(1);
				ans[i].push_back(1);
				continue;
			}
			if (a == 1) {
				for (int j = 0; j < st.size(); j++)
					ans[i].push_back(st[j]);
				ans[i].push_back(1); st.push_back(1);
			}
			else {
				while (st.back() != a - 1) st.pop_back();
				for (int j = 0; j < st.size(); j++)
					ans[i].push_back(st[j]);
				ans[i].back() = a; st.back() = a;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < ans[i].size(); j++) {
				cout << ans[i][j];
				if (j + 1 < ans[i].size()) cout << ".";
			}
			cout << '\n';
		}
	}
	return 0;
}