#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[300009], l[300009], r[300009];
vector<int> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];
		st.clear();
		for (int i = 1; i <= n; i++) {
			if (st.empty()) {
				st.push_back(a[i]);
				continue;
			}
			int p = st.back();
			while (!st.empty() && st.back() < a[i]) {
				p = st.back();
				st.pop_back();
			}
			st.push_back(p);
		}
		if (st.size() <= 1) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}