#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const ld eps = 1e-12;
const int buben = 100;

bool lt(ld a, ld b)
{
	return b - a > eps;
}

bool eq(ld a, ld b)
{
	return abs(a - b) <= eps;
}

bool leq(ld a, ld b)
{
	return lt(a, b) || eq(a, b);
}

bool gt(ld a, ld b)
{
	return a - b > eps;
}

bool geq(ld a, ld b)
{
	return gt(a, b) || eq(a, b);
}

struct pt
{
	ld x, y;
	pt() {}
	pt(ld x, ld y) : x(x), y(y) {}
	pt operator-(const pt& other) const
	{
		return {x - other.x, y - other.y};
	}
	pt operator+(const pt& other) const
	{
		return {x + other.x, y + other.y};
	}
	pt operator*(ld k) const
	{
		return {x  * k, y * k};
	}
};

ld cross(const pt& p, const pt& q)
{
	return p.x * q.y - p.y * q.x;
}

ld dot(const pt& p, const pt& q)
{
	return p.x * q.x + p.y * q.y;
}

ld dist(const pt& a, const pt& b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct line
{
	ld a, b, c;
	line(ld aa, ld bb, ld cc)
	{
		ld k = sqrt(aa * aa + bb * bb);
		a = aa / k, b = bb / k, c = cc / k;
	}
	line(const pt& p, const pt& q)
	{
		a = p.y - q.y;
		b = q.x - p.x;
		c = cross(p, q);
		ld k = sqrt(a * a + b * b);
		a /= k, b /= k, c /= k;
	}
};

pt intersect(const line& l, const line& m)
{
	ld a1 = l.a, b1 = l.b, c1 = -l.c;
	ld a2 = m.a, b2 = m.b, c2 = -m.c;
	ld det = a1 * b2 - a2 * b1;
	assert(!eq(det, 0));
	ld det1 = c1 * b2 - c2 * b1;
	ld det2 = a1 * c2 - a2 * c1;
	return {det1 / det, det2 / det};
}

struct circle
{
	pt c;
	ld r;
};

ld dist(const pt& p, const line& l)
{
	ld alpha = -(p.x * l.a + p.y * l.b + l.c);
	return abs(alpha);
}

pt ortho(const pt& p, const line& l)
{
	ld alpha = -(p.x * l.a + p.y * l.b + l.c);
	pt n = {l.a, l.b};
	return p + n * alpha;
}

vector<pt> intersect(const circle& c, const line& l)
{
	ld d = dist(c.c, l);
	if (gt(d, c.r)) {
		return {};
	}
	pt h = ortho(c.c, l);
	if (eq(d, c.r)) {
		return {h};
	}
	ld x = sqrt(c.r * c.r - d * d);
	pt v = {l.b, -l.a};
	return {h + v * x, h - v * x};
}

vector<pt> intersect(const circle& c1, const circle& c2)
{
	ld x1 = c1.c.x, y1 = c1.c.y, r1 = c1.r;
	ld x2 = c2.c.x, y2 = c2.c.y, r2 = c2.r;
	line l(2 * (x1 - x2), 2 * (y1 - y2), r1 * r1 - r2 * r2 - x1 * x1 + x2 * x2 - y1 * y1 + y2 * y2);
	return intersect(c1, l);
}

bool inside(const pt& p, const circle& c)
{
	return leq(dist(p, c.c), c.r);
}

bool ok(const circle& t, const circle& c1, const circle& c2)
{
	vector<pt> v = intersect(c1, c2);
	if (inside(c1.c, c2)) {
		v.pb(c1.c);
	}
	if (inside(c2.c, c1)) {
		v.pb(c2.c);
	}
	for (pt& p : v) {
		if (inside(p, t)) {
			return true;
		}
	}
	return false;
}

bool valid(const vector<circle>& c)
{
	return ok(c[0], c[1], c[2]) || ok(c[1], c[0], c[2]) || ok(c[2], c[0], c[1]);
}

int main()
{

	//ifstream cin("strictly-off.in");
	//ofstream cout("strictly-off.out");
	//freopen("input.txt", "r", stdin);
	//freopen("threed.out", "w", stdout);
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	/*ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/

	ld t1, t2;
	cin >> t1 >> t2;

	cout << fixed;
	cout.precision(12);

	pt cinema, shop, house;
	cin >> cinema.x >> cinema.y;
	cin >> house.x >> house.y;
	cin >> shop.x >> shop.y;

	ld cs = dist(cinema, shop);
	ld ch = dist(cinema, house);
	ld sh = dist(shop, house);

	ld lf = 0, rg = min(cs + t1, ch + t2);
	//cout << lf << " " << rg << "\n";

	if (geq(ch + t2, cs + sh)) {
		cout << min(cs + sh + t1, ch + t2) << "\n";
		return 0;
	}

	for (int op = 0; op < buben; ++op) {
		ld md = (lf + rg) / 2;
		vector<circle> c;
		c.pb({cinema, md});
		c.pb({shop, cs + t1 - md});
		c.pb({house, ch + t2 - md});
		if (valid(c)) {
			lf = md;
		} else {
			rg = md;
		}
	}

	cout << lf << "\n";

}