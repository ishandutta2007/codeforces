#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int ds[1009], sz[1009];
multiset<int> st;

int uf(int n)
{
	if (ds[n] == n) return n;
	return ds[n] = uf(ds[n]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ds[i] = i;
		sz[i] = 1;
		st.insert(-1);
	}
	int k = 1;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		int ua = uf(a), ub = uf(b);
		if (ua == ub)
			k++;
		else {
			st.erase(st.find(-sz[ua]));
			st.erase(st.find(-sz[ub]));
			st.insert(-(sz[ua] + sz[ub]));
			sz[ua] += sz[ub];
			ds[ub] = ua;
		}
		auto p = st.begin();
		int ans = 0;
		for (int i = 0; i < k && p != st.end(); i++) {
			ans -= (*p);
			p++;
		}
		cout << ans - 1 << '\n';
	}
	return 0;
}