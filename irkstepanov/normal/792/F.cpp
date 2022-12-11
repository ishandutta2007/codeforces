#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const ll buben = 1e6;

const ld eps = 1e-9;

bool lt(ld a, ld b)
{
	return b - a > eps;
}

bool gt(ld a, ld b)
{
	return a - b > eps;
}

bool eq(ld a, ld b)
{
	return abs(a - b) <= eps;
}

bool leq(ld a, ld b)
{
	return lt(a, b) || eq(a, b);
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
	bool operator<(const pt& other) const
	{
		if (x != other.x) {
			return x < other.x;
		}
		return y < other.y;
	}
	bool operator==(const pt& other) const
	{
		return x == other.x && y == other.y;
	}
};

ld cross(const pt& p, const pt& q)
{
	return p.x * q.y - p.y * q.x;
}

set<pt> lower;

bool above(const pt& p)
{
	if (lower.empty()) {
		return false;
	}
	if (sz(lower) == 1) {
		pt q = *lower.begin();
		return eq(p.x, q.x) && leq(q.y, p.y);
	}
	pt f = *(--lower.end());
	if (gt(p.x, f.x) || (eq(p.x, f.x) && lt(p.y, f.y))) {
		return false;
	}
	if (eq(p.x, f.x)) {
		return true;
	}
	f = *lower.begin();
	if (lt(p.x, f.x) || (eq(p.x, f.x) && lt(p.y, f.y))) {
		return false;
	}
	if (eq(p.x, f.x)) {
		return true;
	}
	set<pt>::iterator it = lower.lower_bound(p);
	set<pt>::iterator pr = it;
	--pr;
	return geq(cross(*it - *pr, p - *pr), 0);
}

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;

	ll m;
	cin >> m;

	int j = 0;

	lower.insert({0, 0});

	//multiset<ld> frac;

	for (int step = 1; step <= q; ++step) {
		int type;
		cin >> type;
		if (type == 1) {
			ll x, y;
			cin >> x >> y;
			x = (x + j) % buben + 1;
			y = (y + j) % buben + 1;
			pt p = {ld(x), ld(y)};

			if (lower.empty()) {
				lower.insert(p);
				//frac.insert(p.y / p.x);
			} else if (!above(p)) {
				pt f = *(--lower.end());
				if ((p.x == f.x && p.y < f.y) || p.x > f.x) {
					while (sz(lower) >= 2 && cross(*(--lower.end()) - *(--(--lower.end())), p - *(--lower.end())) <= 0) {
						//frac.erase(frac.lower_bound((--lower.end())->y / (--lower.end())->x));
						lower.erase(--lower.end());
					}
					if (sz(lower) == 1 && p.x == lower.begin()->x && p.y <= lower.begin()->y) {
						lower.clear();
						//frac.clear();
					}
					lower.insert(p);
					//frac.insert(p.y / p.x);
				} else if (p.x < f.x) {
					f = *lower.begin();
					if ((p.x == f.x && p.y < f.y) || p.x < f.x) {
						while (sz(lower) >= 2 && cross(*lower.begin() - p, *(++lower.begin()) - *(lower.begin())) <= 0) {
							//frac.erase(frac.lower_bound((lower.begin())->y / (lower.begin())->x));
							lower.erase(lower.begin());
						}
						if (sz(lower) == 1 && p.x == lower.begin()->x && p.y <= lower.begin()->y) {
							lower.clear();
							//frac.clear();
						}
						lower.insert(p);
						//frac.insert(p.y / p.x);
					} else if (p.x > f.x) {
						set<pt>::iterator it = lower.lower_bound(p);
						set<pt>::iterator pr = it;
						--pr;
							while (it != --lower.end()) {
								set<pt>::iterator nx = it;
								++nx;
								if (cross(*it - p, *nx - *it) <= 0) {
									//frac.erase(frac.lower_bound(it->y / it->x));
									lower.erase(it);
									it = nx;
								} else {
									break;
								}
							}
							while (pr != lower.begin()) {
								set<pt>::iterator nx = pr;
								--nx;
								if (cross(*pr - *nx, p - *pr) <= 0) {
									//frac.erase(frac.lower_bound(pr->y / pr->x));
									lower.erase(pr);
									pr = nx;
								} else {
									break;
								}
							}
							lower.insert(p);
							//frac.insert(p.y / p.x);
					}
				}
			}
		} else {
			ll t, h;
			cin >> t >> h;
			t = (t + j) % buben + 1;
			h = (h + j) % buben + 1;
			//pt lowest = {ld(h) / ld(t), 0};
			pt highest = {ld(h) / ld(t), ld(m) / ld(t)};
			if (above(highest)) {
				cout << "YES\n";
				j = step;
			} else {
				/*bool ok = false;
				for (pt q : lower) {
					if (geq(cross(q, highest), 0) && leq(q.x, highest.x)) {
						 ok = true;
						 //cout << q.x << " " << q.y << " " << highest.x << " " << highest.y << "\n";
						 break;
					}
				}
				if (ok) {
					cout << "YES\n";
					j = step;
				} else {
					cout << "NO\n";
				}*/
				/*if (!frac.empty() && leq(*frac.begin(), ld(m) / ld(h))) {
					cout << "YES\n";
					j = step;
				} else {
					cout << "NO\n";
				}*/
				cout << "NO\n";
			}
		}

		/*cout << "LOWER\n";
		for (pt p : lower) {
			cout << p.x << " " << p.y << "\n";
		}*/
		/*cout << "UPPER\n";
		for (pt p : upper) {
			cout << p.x << " " << p.y << "\n";
		}*/
		//cout << "\n";
	}

}