#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int a[1000009];
vector<pair<long long, long long> > st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st.push_back(make_pair(a[i], 1));
		int sz = st.size();
		while (st.size() > 1 && 1LL * st[sz - 2].first * st[sz - 1].second >= 1LL * st[sz - 1].first * st[sz - 2].second) {
			long long s = st[sz - 1].first + st[sz - 2].first, l = st[sz - 1].second + st[sz - 2].second;
			st.pop_back(); st.pop_back();
			st.push_back(make_pair(s, l));
			sz--;
		}
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	int c = 1;
	for (int i = 0; i < st.size(); i++) {
		double t = (double)st[i].first / (double)st[i].second;
		for (int j = 0; j < st[i].second; j++)
			cout << t << '\n';
	}
	return 0;
}