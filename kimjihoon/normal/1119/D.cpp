#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

long long s[100009], ps[100009];
pair<long long, int> p[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n);
	for (int i = 0; i < n - 1; i++)
		p[i].first = s[i + 1] - s[i];
	p[n - 1].first = 1000000000000000009LL;
	sort(p, p + n);
	ps[0] = p[0].first;
	for (int i = 1; i < n; i++)
		ps[i] = ps[i - 1] + p[i].first;
	for (int i = 0; i < n; i++)	
		p[i].second = i;
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		long long l, r, d; cin >> l >> r; d = r - l + 1;
		auto tp = lower_bound(p, p + n, make_pair(d, 0));
		if ((*tp).second == 0) cout << (d * 1LL * (n - (*tp).second)) << " ";
		else cout << ps[(*tp).second - 1] + (d * 1LL * (n - (*tp).second)) << " ";
	}
	cout << '\n';
	return 0;
}