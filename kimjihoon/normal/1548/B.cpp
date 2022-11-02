#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

long long a[200009], st[800009];

void init(int tn, int s, int e)
{
	if (s == e) {
		st[tn] = a[s];
		return;
	}
	int md = (s + e) / 2;
	init(tn * 2, s, md);
	init(tn * 2 + 1, md + 1, e);
	st[tn] = gcd(st[tn * 2], st[tn * 2 + 1]);
}

long long qry(int tn, int s, int e, int ts, int te)
{
	if (e < ts || te < s) return 0LL;
	if (ts <= s && e <= te) return st[tn];
	int md = (s + e) / 2;
	return gcd(qry(tn * 2, s, md, ts, te), qry(tn * 2 + 1, md + 1, e, ts, te));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 1) a[i - 1] = abs(a[i - 1] - a[i]);
		}
		if (n > 1) init(1, 1, n - 1);
		int ans = 1, s = 1;
		for (int i = 1; i <= n; i++) {
			while (s < i && qry(1, 1, n - 1, s, i - 1) == 1) s++;
			ans = max(ans, i - s + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}