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
	ll x, y;
	pt() {}
	pt(ll x, ll y) : x(x), y(y) {}
	pt operator-(const pt& other) const
	{
		return {x - other.x, y - other.y};
	}
	bool operator<(const pt& other) const
	{
		if (x != other.x) {
			return x < other.x;
		}
		return y < other.y;
	}
};

ll dist2(const pt& a, const pt& b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll cross(const pt& p, const pt& q)
{
	return p.x * q.y - p.y * q.x;
}

pt start;

bool comp(const pt& a, const pt& b)
{
	pt u = a - start, v = b - start;
	if (cross(u, v) != 0) {
		return cross(u, v) > 0;
	}
	return dist2(a, start) < dist2(b, start);
}

vector<pt> convex(vector<pt> v)
{
	sort(all(v));
	start = v[0];
	sort(v.begin() + 1, v.end(), comp);
	vector<pt> ans;
	ans.pb(start);
	int s = 1;
	for (int i = 1; i < sz(v); ++i) {
		while (s >= 2 && cross(ans[s - 1] - ans[s - 2], v[i] - ans[s - 1]) <= 0) {
			ans.pop_back();
			--s;
		}
		++s;
		ans.pb(v[i]);
	}
	return ans;
}

int main()
{

	//ifstream cin("strictly-off.in");
	//ofstream cout("strictly-off.out");
	//freopen("input.txt", "r", stdin);
	//freopen("threed.out", "w", stdout);
	//ifstream cin("input.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pt> p;
	while (n--) {
		pt v;
		cin >> v.x >> v.y;
		p.pb({v.x - 1, v.y});
		p.pb({v.x + 1, v.y});
		p.pb({v.x, v.y - 1});
		p.pb({v.x, v.y + 1});
	}

	p = convex(p);

	ll ans = 0;
	for (int i = 0; i < sz(p); ++i) {
		pt u = p[i], v = p[(i + 1) % sz(p)];
		ans += max(abs(u.x - v.x), abs(u.y - v.y));
	}

	cout << ans << "\n";

}