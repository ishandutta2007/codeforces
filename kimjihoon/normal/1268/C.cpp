#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, ft[200009], r[200009];

void up(int i)
{
	while (i <= n) {
		ft[i]++;
		i += (i & (-i));
	}
}

int sum(int i)
{
	int s = 0;
	while (i > 0) {
		s += ft[i];
		i -= (i & (-i));
	}
	return s;
}

int bs(int s, int e, int t)
{
	int md = (s + e) / 2;
	if (s >= e) return md;
	if (sum(md) >= t) return bs(s, md, t);
	else bs(md + 1, e, t);
}
	
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		r[a] = i;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += i - 1 - sum(r[i]);
		int s, e;
		s = bs(1, n, i / 2);
		if (i % 2 == 1) e = bs(1, n, i / 2 + 1);
		else e = s;
		if (!(s <= r[i] && r[i] <= e)) {
			if (r[i] < s) ans += s - r[i] - 1 - sum(s - 1);
			else ans += r[i] - e + sum(e) - i;
		}
		else
			ans -= i / 2;
		cout << ans << " ";
		up(r[i]);
	}
	cout << '\n';
	return 0;
}