#include <iostream>
using namespace std;

int n, ans[200009];
long long a[200009], ft[200009];

void up(int i, int w)
{
	while (i <= n) {
		ft[i] += w;
		i += (i & (-i));
	}
}

long long sum(int i)
{
	long long s = 0;
	while (i) {
		s += ft[i];
		i -= (i & (-i));
	}
	return s;
}

int bs(int s, int e, long long w)
{
	int md = (s + e + 1) / 2;
	if (s >= e) return md;
	if (sum(md - 1) <= w) return bs(md, e, w);
	else return bs(s, md - 1, w);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		up(i, i);
	for (int i = n; i >= 1; i--) {
		ans[i] = bs(1, n, a[i]);
		up(ans[i], -ans[i]);
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << '\n';
	return 0;
}