#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

int a[100009];

vector<int> ans;
queue<int> q;
set<int> st, rst;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		rst.clear(); st.clear(); ans.clear();
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			st.insert(i);
			rst.insert(i);
		}
		st.insert(n + 1); rst.insert(n + 1);
		for (int i = 1; i <= n; i++) {
			int ti = (i % n) + 1;
			if (gcd(a[i], a[ti]) != 1) 
				st.erase(i);
		}
		int p = 1;
		while (st.size() > 1) {
			p = (*st.lower_bound(p));
			if (p == n + 1) p = (*st.begin());
			int tp = (*rst.upper_bound(p));
			if (tp == n + 1) tp = (*rst.begin());
			if (gcd(a[p], a[tp]) == 1) {
				st.erase(tp); rst.erase(tp);
				if (st.empty()) break;
				ans.push_back(tp);
				int sp = (*rst.upper_bound(tp));
				if (sp == n + 1) sp = (*rst.begin());
				if (gcd(a[p], a[sp]) != 1) st.erase(p);
				p = sp;
			}
		}
		cout << ans.size() << " ";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}