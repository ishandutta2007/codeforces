#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> p[300009];
vector<pair<int, pair<int, int> > > l;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q; cin >> q;
	for (int ti = 1; ti <= q; ti++) {
		int n; cin >> n;
		l.clear();
		int rc = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			if (p[a].first < ti) {
				p[a].first = ti; p[a].second = l.size();
				l.push_back(make_pair(a, make_pair(i, i)));
				rc++;
			}
			else
				l[p[a].second].second.second = i;
		}
		sort(l.begin(), l.end());
		int mx = 0, c = 0, r = -1;
		for (int i = 0; i < l.size(); i++) {
			if (l[i].second.first <= r) {
				c = 0; r = -1;
			}
			c++; r = max(r, l[i].second.second);
			mx = max(mx, c);
		}
		cout << rc - mx << '\n';
	}
	return 0;
}