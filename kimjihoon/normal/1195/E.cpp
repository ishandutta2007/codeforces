#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int p[3009][3009];
deque<pair<int, int> > dq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, a, b; cin >> n >> m >> a >> b;
	int g, x, y, z; cin >> g >> x >> y >> z;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			p[i][j] = g;
			g = (1LL * g * x + 1LL * y) % (1LL * z);
		}
	for (int i = 0; i < n; i++) {
		while (!dq.empty())
			dq.pop_back();
		for (int j = 0; j < m; j++) {
			while (!dq.empty() && dq.back().first > p[i][j])
				dq.pop_back();
			dq.push_back(make_pair(p[i][j], j));
			while (!dq.empty() && dq.front().second <= j - b)
				dq.pop_front();
			if (j - b + 1 >= 0)
				p[i][j - b + 1] = dq.front().first;
		}
	}
	long long ans = 0;
	for (int j = 0; j <= m - b; j++) {
		while (!dq.empty())
			dq.pop_back();
		for (int i = 0; i < n; i++) {
			while (!dq.empty() && dq.back().first > p[i][j])
				dq.pop_back();
			dq.push_back(make_pair(p[i][j], i));
			while (!dq.empty() && dq.front().second <= i - a)
				dq.pop_front();
			if (i - a + 1 >= 0) {
				p[i - a + 1][j] = dq.front().first;
				ans += p[i - a + 1][j];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}