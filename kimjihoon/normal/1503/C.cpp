#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ct
{
	int a, c, i;
	bool operator<(const ct &r) const {
		return a < r.a;
	}
};

ct c[100009];
vector<ct> v;

long long ps(int s, int e)
{
	int mx = 0; s--; e--;
	long long ans = 0;
	for (int i = s; i < e; i++) {
		mx = max(mx, v[i].a + v[i].c);
		if (mx < v[i + 1].a)
			ans += v[i + 1].a - mx;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	long long rs = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i].a >> c[i].c;
		c[i].i = i;
		rs += c[i].c;
	}
	sort(c + 1, c + n + 1);
	int pi = 1;
	for (int i = 1; i <= n; i++) {
		if (c[i].i == 1) {
			pi = i;
			break;	
		}
	}
	for (int i = 1; i <= n; i++)
		v.push_back(c[i]);
	long long ans = ps(pi, n) + ps(1, pi);
	v.clear();
	for (int i = 1; i <= n; i++)
		if (i != pi)
			v.push_back(c[i]);
	if (pi != 1 && pi != n) ans = min(ans, ps(1, n - 1));
	cout << ans + rs << '\n';
	return 0;
}