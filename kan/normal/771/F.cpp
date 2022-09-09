#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;

struct P {
	ll x, y;
	void read() { scanf("%lld%lld", &x, &y); }
	P operator - (const P & b) const { return P{x - b.x, y - b.y}; }
	void operator += (const P & b) { x += b.x, y += b.y; }
	ll operator * (const P & b) const { return x * b.y - y * b.x; }
	ll cross(const P & b, const P & c) const {
		return (b - *this) * (c - *this);
	}
	bool isRight() const { return x > 0 || (x == 0 && y > 0); }
	bool operator < (const P & b) const {
		if(isRight() != b.isRight())
			return isRight();
		return *this * b < 0;
	}
};
debug & operator << (debug & dd, P p) {
	dd << make_pair(p.x, p.y);
	return dd;
}

struct L2 {
	P one, two;
	P dir() const { return two - one; }
	bool operator < (const L2 & b) const { return dir() < b.dir(); }
	long double get_coeff(const L2 & b) const {
		long double r = (b.dir() * (one - b.one)) / (long double) (dir() * b.dir());
		return r;
	}
	bool isParallel(const L2 & b) const { return dir() * b.dir() == 0; }
	// checks if this line is more important than the other parallel line
	bool isBetter(const L2 & b) const {
		assert(isParallel(b));
		return (b.one - one) * (two - one) < 0;
	}
	// checks if this line is less important than two neighbouring lines
	bool isBelow(const L2 & a, const L2 & c) const {
		return get_coeff(a) >= get_coeff(c);
	}
	pair<long double, long double> intersect(const L2 & b) const {
		long double r = get_coeff(b);
		return make_pair(one.x + r * (two - one).x, one.y + r * (two - one).y);
	}
};
debug & operator << (debug & dd, L2 line) {
	dd << make_pair(line.one, line.two);
	return dd;
}

deque<L2> getHull(vector<L2> halfplanes) {
	sort(halfplanes.begin(), halfplanes.end());
	debug() << imie(halfplanes);
	deque<L2> hull;
	#define sec_back(vect) vect[(int) vect.size() - 2]
	for(L2 line : halfplanes) {
		if(!hull.empty() && line.isParallel(hull.back())) {
			if(hull.back().isBetter(line))
				line = hull.back();
			hull.pop_back();
		}
		while((int) hull.size() >= 2 && hull.back().isBelow(sec_back(hull), line))
			hull.pop_back();
		hull.push_back(line);
	}
	while((int) hull.size() >= 3) {
		if(hull.back().isBelow(sec_back(hull), hull[0]))
			hull.pop_back();
		else if(hull[0].isBelow(hull.back(), hull[1]))
			hull.pop_front();
		else break;
	}
	#undef sec_back
	debug() << imie(hull);
	return hull;
}

long double test_case() {
	int n;
	scanf("%d", &n);
	P origin;
	origin.read();
	vector<P> points(n - 1);
	for(P & p : points) {
		p.read();
		p = p - origin;
	}
	sort(points.begin(), points.end());
	debug() << imie(points);
	vector<L2> halfplanes;
	for(int i = 0; i < (int) points.size(); ++i) {
		int j = (i + 1) % points.size();
		halfplanes.push_back(L2{points[i], points[j]});
	}
	int pointer = 0;
	for(int i = 0; i < (int) points.size(); ++i) {
		pointer = max(pointer, i + 1);
		while(points[i] * points[pointer % points.size()] < 0)
			++pointer;
		if(i != pointer % (int) points.size())
			halfplanes.push_back(L2{points[i], points[pointer % points.size()]});
	}
	debug() << imie(halfplanes);
	for(L2 & line : halfplanes) {
		if(line.one * line.two == 0)
			return 0;
		if(line.one * line.two > 0)
			swap(line.one, line.two);
		line.one += origin;
		line.two += origin;
	}
	
	const int MAX = 1e6;
	vector<P> corners{P{-MAX, MAX}, P{MAX, MAX}, P{MAX, -MAX}, P{-MAX, -MAX}};
	for(int i = 0; i < (int) corners.size(); ++i) {
		int j = (i + 1) % corners.size();
		halfplanes.push_back(L2{corners[i], corners[j]});
	}
	deque<L2> hull = getHull(halfplanes);
	vector<pair<long double, long double>> polygon;
	long double area = 0;
	for(int i = 0; i < (int) hull.size(); ++i) {
		int j = (i + 1) % hull.size();
		polygon.push_back(hull[i].intersect(hull[j]));
	}
	debug() << imie(polygon);
	for(int i = 0; i < (int) polygon.size(); ++i) {
		int j = (i + 1) % polygon.size();
		area += polygon[i].first * polygon[j].second
				- polygon[i].second * polygon[j].first;
	}
	return abs(area) / 2;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--)
		printf("%.12lf\n", (double) test_case());
}