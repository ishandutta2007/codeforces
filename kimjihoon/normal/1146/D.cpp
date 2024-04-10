#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool vs[10000009];

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

queue<int> q;

long long pc(int m, int g)
{
	int t = m / g;
	return 1LL * t * (t + 1) / 2LL * g + 1LL * (m / g + 1) * (m % g + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int m, a, b; cin >> m >> a >> b;
	int g = gcd(a, b);
	int p = 1, c = 1;
	long long ans = 1;
	vs[0] = true;
	while (p <= m) {
		if (p - a < 0 || !vs[p - a]) {
			ans += c; p++;
			continue;
		}
		vs[p] = true; q.push(p);
		while (!q.empty()) {
			int hn = q.front(); q.pop(); c++;
			if (hn + a <= p && !vs[hn + a]) { vs[hn + a] = true; q.push(hn + a); }
			if (hn - b >= 0 && !vs[hn - b]) { vs[hn - b] = true; q.push(hn - b); }
		}
		ans += c;
		if (c == p / g + 1) break;
		p++;
	}
	if (p < m) ans += pc(m, g) - pc(p, g);
	cout << ans << '\n';
	return 0;
}