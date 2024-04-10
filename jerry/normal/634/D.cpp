#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<pair<int, ll> > st;
set<pair<ll, int> > re;
ll ans, p; int n, x;

int main()
{ cin.sync_with_stdio(0); cin.tie(0);
	int d, m; cin >> d >> n >> m;
	while (m--)
	{
		cin >> x >> p;
		st.emplace(x, p);
	}
	st.emplace(0, 0ll);
	st.emplace(d, 0ll);
	x = 0;
	while (x < d)
	{
		re.emplace((*st.begin()).second, (*st.begin()).first);
		st.erase(st.begin());
		while (x < (*st.begin()).first)
		{
			while (!re.empty() && (*re.begin()).second+n <= x) re.erase(re.begin());
			if (re.empty()) { cout << -1 << endl; return 0; }
			int X = min((*st.begin()).first, (*re.begin()).second+n);
			ans += (*re.begin()).first*(X-x);
			x = X;
		}
	}
	cout << ans << endl;
	return 0;
}