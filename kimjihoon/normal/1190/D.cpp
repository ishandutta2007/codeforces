#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct pnt
{
	int x, y;
	bool operator<(const pnt &r) const {
		if (y != r.y) return y > r.y;
		return x < r.x;
	}
};

int c = 0, x[200009], ft[200009];
bool vs[200009];
pnt p[200009];
map<int, int> mp;

void up(int i)
{
	while (i <= c + 2) {
		ft[i]++;
		i += (i & (-i));
	}
}

int sum(int i)
{
	int s = 0;
	while (i) {
		s += ft[i];
		i -= (i & (-i));
	}
	return s;
}

int cnt(int s, int e)
{
	if (s > e) return 0;
	return sum(e) - sum(s - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		x[i] = p[i].x;
	}
	sort(x, x + n);
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		if (i == 0 || x[i] != x[i - 1]) c++;
		mp[x[i]] = c;
	}
	for (int i = 0; i < n; i++)
		p[i].x = mp[p[i].x];
	long long ans = 0, pc = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || p[i].y != p[i - 1].y) {
			ans += pc * (pc + 1) / 2;
			long long t = cnt(1, p[i].x - 1);
			ans -= t * (t + 1) / 2;
		}
		int tx;
		if (i == n - 1 || p[i].y != p[i + 1].y) tx = c + 1;
		else tx = p[i + 1].x;
		long long t = cnt(p[i].x + 1, tx - 1);
		ans -= t * (t + 1) / 2;
		if (!vs[p[i].x]) {
			vs[p[i].x] = true;
			up(p[i].x);
			pc++;
		}
	}
	ans += pc * (pc + 1) / 2;
	cout << ans << '\n';
	return 0;
}