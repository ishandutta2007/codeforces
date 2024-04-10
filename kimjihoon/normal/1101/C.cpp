#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

struct ps
{
	int s, e, i;
	bool operator<(const ps &r) const {
		if (s != r.s) return s < r.s;
		return e < r.e;
	}
};

ps p[100009];
int ans[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i].s >> p[i].e;
			p[i].i = i;
		}
		sort(p, p + n);
		int t = 1, mx = p[0].e;
		bool f = false;
		for (int i = 0; i < n; i++) {
			if (mx < p[i].s) {
				t = t % 2 + 1;
				f = true;
			}
			mx = max(mx, p[i].e);
			ans[p[i].i] = t;
		}
		if (!f) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}