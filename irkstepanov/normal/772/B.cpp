#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct pt
{
	ld x, y;
	pt() {}
	pt(ld x, ld y) : x(x), y(y) {}
};

ld cross(const pt& p, const pt& q)
{
	return p.x * q.y - p.y * q.x;
}

struct line
{
	ld a, b, c;
	line(const pt& p, const pt& q)
	{
		a = p.y - q.y;
		b = q.x - p.x;
		c = cross(p, q);
		ld tmp = sqrt(a * a + b * b);
		a /= tmp, b /= tmp, c /= tmp;
	}
};

ld dist(const pt& p, const line& l)
{
	return abs(l.a * p.x + l.b * p.y + l.c);
}

const ld inf = 1e18;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;

	vector<pt> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x >> p[i].y;
	}

	ld ans = inf;
	for (int i = 0; i < n; ++i) {
		line l(p[(i - 1 + n) % n], p[(i + 1) % n]);
		ans = min(ans, dist(p[i], l) / 2);
	}

	cout << fixed;
	cout.precision(12);
	cout << ans << "\n";

}