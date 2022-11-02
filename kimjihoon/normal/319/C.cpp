#include <iostream>
#include <deque>
using namespace std;
typedef long long ll;

deque<int> dq;
int n, a[100009], b[100009];
ll d[100009];

ll cost(int p, int q)
{
	return 1LL * b[p] * (a[q] - 1) + 1LL * b[q];
}

int crs(int p, int q)
{
	int s = q + 1, e = n + 1, md = 0;
	while (s < e) {
		md = (s + e) / 2;
		if (d[p] + cost(p, md) < d[q] + cost(q, md)) s = md + 1;
		else e = md;
	}
	return (s + e) / 2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	dq.push_back(1); d[1] = b[1];
	for (int i = 2; i <= n; i++) {
		while (dq.size() > 1) {
			int p = dq.front(); dq.pop_front();
			if (crs(p, dq.front()) > i) {
				dq.push_front(p);
				break;
			}
		}
		int j = dq.front();
		d[i] = d[j] + cost(j, i);
		while (dq.size() > 1) {
			int q = dq.back(); dq.pop_back();
			if (crs(dq.back(), q) < crs(q, i)) {
				dq.push_back(q);
				break;
			}
		}
		dq.push_back(i);
	}
	cout << d[n] << '\n';
	return 0;
}