#include <iostream>
#include <list>
#include <utility>
#include <algorithm>
using namespace std;

list<int> l;
pair<int, int> p[100009];
int a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		mx = max(mx, a);
		l.push_back(a);
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (l.front() == mx) {
			c = i + 1;
			break;
		}
		int a = l.front(); l.pop_front(); int b = l.front(); l.pop_front();
		p[i] = make_pair(a, b);
		l.push_front(max(a, b)); l.push_back(min(a, b));
	}
	for (int i = 0; i < n; i++) {
		a[i] = l.front(); l.pop_front();
	}
	for (int i = 0; i < q; i++) {
		long long m; cin >> m;
		if (m < 1LL * c) cout << p[m - 1].first << " " << p[m - 1].second << '\n';
		else {
			long long r = (m - 1LL * c) % (1LL * (n - 1));
			cout << mx << " " << a[r + 1] << '\n';
		}
	}
	return 0;
}