#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;

double urand() { return rand() / (1.0 + RAND_MAX); }

// === tick a time ===
#include <ctime>
double tick() {
    static clock_t oldtick;
    clock_t newtick = clock();
    double diff = 1.0*(newtick - oldtick) / CLOCKS_PER_SEC;
    oldtick = newtick;
    return diff;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for (int i = 0; i < v.size(); os << v[i++])
        if (i > 0) os << " ";
    os << "]";
    return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    os << "[";
    for (int i = 0; i < v.size(); os << v[i++])
        if (i > 0) os << endl << " ";
    os << "]";
    return os;
}

const double PI = acos(-1.0);

// implementation note: use EPS only in this function
// usage note: check sign(x) < 0, sign(x) > 0, or sign(x) == 0
const double EPS = 1e-8;
int sign(double x) {
    if (x < -EPS) return -1;
    if (x > +EPS) return +1;
    return 0;
}

using Real = double;
struct point {
    Real x, y;
    point &operator+=(point p) { x += p.x; y += p.y; return *this; }
    point &operator-=(point p) { x -= p.x; y -= p.y; return *this; }
    point &operator*=(Real a)         { x *= a;     y *= a;     return *this; }
    point &operator/=(Real a)         { return *this *= (1.0/a); }
    point operator-() const        { return {-x, -y}; }
    bool operator<(point p) const {
        int s = sign(x - p.x);
        return s ? s < 0 : sign(y - p.y) < 0;
    }
};
bool operator==(point p, point q) { return !(p < q) && !(q < p); }
bool operator!=(point p, point q) { return p < q || q < p; }
bool operator<=(point p, point q) { return !(q < p); }
point operator+(point p, point q) { return p += q; }
point operator-(point p, point q) { return p -= q; }
point operator*(Real a, point p) { return p *= a; }
point operator*(point p, Real a) { return p *= a; }
point operator/(point p, Real a) { return p /= a; }
Real dot(point p, point q) { return p.x*q.x+p.y*q.y; }
Real cross(point p, point q) { return p.x*q.y-p.y*q.x; } // left turn > 0
Real norm2(point p) { return dot(p,p); }
point orth(point p) { return {-p.y, p.x}; }
Real norm(point p) { return sqrt(dot(p,p)); }
Real arg(point p) { return atan2(p.y, p.x); }
Real arg(point p, point q){ return atan2(cross(p,q), dot(p,q)); }

istream &operator>>(istream &is, point &p) { is>>p.x>>p.y;return is; }
ostream &operator<<(ostream &os, const point &p) { os<<"("<<p.x<<","<<p.y<<")"; return os; }


// exact comparison by polar angle
// usage: sort(all(ps), polar_angle(origin, direction));
struct polar_angle {
    const point o;
    const int s; // +1 for ccw, -1 for cw
    polar_angle(point p = {0,0}, int s = +1) : o(p), s(s) { }
    int quad(point p) const {
        for (int i = 1; i <= 4; ++i, swap(p.x = -p.x, p.y))
            if (p.x > 0 && p.y >= 0) return i;
        return 0;
    }
    bool operator()(point p, point q) const {
        p = p - o; q = q - o;
        if (quad(p) != quad(q)) return s*quad(p) < s*quad(q);
        if (cross(p, q)) return s*cross(p, q) > 0;
        return norm2(p) < norm2(q); // closer first
    }
};

struct line { point p, q; };
bool operator==(line l, line m) {
    return !sign(cross(l.p-l.q,m.p-m.q)) && !sign(cross(l.p-l.q,m.p-l.p));
}

struct segment { point p, q; };
bool operator==(segment l, line m) {
    return (l.p==m.p && l.q==m.q) || (l.p==m.q && l.q==m.p); // do not consider the direction
}
struct circle { point p; Real r; };
bool operator==(circle c, circle d) { return c.p == d.p && !sign(c.r - d.r); }


//-----------------------------------------------------------------------------
// point p is on line l
//-----------------------------------------------------------------------------
vector<point> intersect(line l, point p) {
    if (sign(cross(l.p-p, l.q-p)) != 0) return {};
    return {p};
}
vector<point> intersect(point p, line l) {
    return intersect(l, p);
}

//-----------------------------------------------------------------------------
// point p is on segment s
//-----------------------------------------------------------------------------
vector<point> intersect(segment s, point p) {
    if (sign(cross(s.p-p, s.q-p)) != 0) return {};
    if (sign(    dot(s.p-p, s.q-p))    > 0) return {}; // >    for strict intersect
    return {p};                                                                        // >= for weak intersect
}
vector<point> intersect(point p, segment s) {
    return intersect(s, p);
}

//-----------------------------------------------------------------------------
// intersection of two lines
//
// Derivation: The crosspoint equation is
//     l.p + (l.q - l.p) t == m.p + (m.q - m.p) s ... (CP.1)
// Taking a cross product with (m.q - m.p), we have
//     (m.q - m.p) x (l.q - l.p) t == (m.q - m.p) x (m.p - l.p)
//     ~~~~~~~~~~~~a~~~~~~~~~~~~            ~~~~~~~~~~~~b~~~~~~~~~~~~
//
// If a != 0, these two lines have a proper crosspoint.
// If a == 0 and b == 0, these two lines are the same line.
// Otherwise, these two lines are parallel.
//-----------------------------------------------------------------------------
vector<point> intersect(line l, line m) {
    auto a = cross(m.q - m.p, l.q - l.p);
    auto b = cross(l.p - m.p, l.q - l.p);
    if ( sign(a)) return {m.p + b/a*(m.q - m.p)}; // properly crossing
    if (!sign(b)) return {m.p, m.q};                            // same line
    return {};                                                                        // disjoint parallel
}

//-----------------------------------------------------------------------------
// intersection of line and segment
//
// In CP.1, t must be in [0, 1]. Thus 0 <= b/a <= 1 is required.
// By assuming a > 0, it is equivalent to b >= 0 and b-a <= 0
//-----------------------------------------------------------------------------
vector<point> intersect(line l, segment s) {
    auto a = cross(s.q - s.p, l.q - l.p);
    auto b = cross(l.p - s.p, l.q - l.p);
    if (a < 0) { a *= -1; b *= -1; }
    if (sign(b) < 0 || sign(a-b) < 0) return {};            // no intersect
    if (sign(a) != 0) return {s.p + b/a*(s.q - s.p)}; // properly crossing
    if (sign(b) == 0) return {s.p, s.q};                            // same line
    return {};                                                                                // disjoint parallel
}

//-----------------------------------------------------------------------------
// intersection of two segments
//
// Solve two CP.1s simultaneously.
// If two segments are overlapping, it is bit difficult.
//-----------------------------------------------------------------------------
vector<point> intersect(segment s, segment t) {
    auto a = cross(s.q - s.p, t.q - t.p);
    auto b = cross(t.p - s.p, t.q - t.p);
    auto c = cross(s.q - s.p, s.p - t.p);
    if (a < 0) { a = -a; b = -b; c = -c; }
    if (sign(b) < 0 || sign(a-b) < 0 ||
            sign(c) < 0 || sign(a-c) < 0) return {};            // disjoint
    if (sign(a) != 0) return {s.p + b/a*(s.q - s.p)}; // properly crossing
    vector<point> ps;                                                                 // same line
    auto insert_if_possible = [&](point p) {
        for (auto q: ps) if (sign(dot(p-q, p-q)) == 0) return;
        ps.push_back(p);
    };
    if (sign(dot(s.p-t.p, s.q-t.p)) <= 0) insert_if_possible(t.p);
    if (sign(dot(s.p-t.q, s.q-t.q)) <= 0) insert_if_possible(t.q);
    if (sign(dot(t.p-s.p, t.q-s.p)) <= 0) insert_if_possible(s.p);
    if (sign(dot(t.p-s.q, t.q-s.q)) <= 0) insert_if_possible(s.q);
    return ps;
}

//-----------------------------------------------------------------------------
// reflected point with respect to l
//-----------------------------------------------------------------------------
point reflection(point p, line l) {
    auto a = dot(l.p-l.q, l.p-l.q);
    auto b = dot(l.p-p,     l.p-l.q);
    return 2 * (l.p + a/b*(l.q - l.p)) - p;
}

//-----------------------------------------------------------------------------
// closest point on l
//-----------------------------------------------------------------------------
point projection(point p, line l) {
    auto a = dot(l.p-l.q, l.p-l.q);
    auto b = dot(l.p-p,     l.p-l.q);
    return l.p + a/b*(l.q - l.p);
}

//-----------------------------------------------------------------------------
// closest point on s
//-----------------------------------------------------------------------------
point projection(point p, segment s) {
    auto a = dot(s.p-s.q, s.p-s.q);
    auto b = dot(s.p - p, s.p-s.q);
    if (sign(b)     < 0) return s.p;
    if (sign(a-b) < 0) return s.q;
    return s.p + b/a*(s.q - s.p);
}

//-----------------------------------------------------------------------------
// closest point on c
//-----------------------------------------------------------------------------
point projection(point p, circle c) {
    point v = p - c.p;
    return c.p + c.r * v / norm(v);
}
//-----------------------------------------------------------------------------
// distances
//-----------------------------------------------------------------------------
Real dist(point p, point q) {
    return norm(p-q);
}
Real dist(point p, line l) {
    return dist(p, projection(p, l));
}
Real dist(line l, point p) {
    return dist(p, l);
}
Real dist(line l, line m) {
    if (sign(cross(l.p-l.q,m.p-m.q))) return 0; // cross
    return dist(l.p, m);
}
Real dist(point p, segment s) {
    return dist(p, projection(p, s));
}
Real dist(line l, segment s) {
    if (intersect(l, s).size()) return 0;
    return min(dist(l, s.p), dist(l, s.q));
}
Real dist(segment s, line l) {
    return dist(l, s);
}
Real dist(segment s, segment T) {
    if (intersect(s, T).size()) return 0;
    return min({dist(s.p,T), dist(s.q,T), dist(T.p,s), dist(T.q,s)});
}


//-----------------------------------------------------------------------------
// intersection points of two circles
//-----------------------------------------------------------------------------
vector<point> intersect(circle c, circle d) {
    if (c.r < d.r) swap(c, d);
    auto pow2 = [](Real a) { return a*a; };
    auto g = dot(c.p-d.p, c.p-d.p);
    if (sign(g) == 0) {
        if (sign(c.r-d.r) != 0) return {};
        return {{c.p.x+c.r, c.p.y}, {c.p.x, c.p.y+c.r}, {c.p.x-c.r, c.p.y}};
    }
    int inner = sign(g-pow2(c.r-d.r));
    int outer = sign(g-pow2(c.r+d.r));
    if (inner < 0 || outer > 0) return {};
    if (inner == 0) return {(c.r*d.p-d.r*c.p)/(c.r-d.r)};
    if (outer == 0) return {(c.r*d.p+d.r*c.p)/(c.r+d.r)};
    auto eta = (pow2(c.r) - pow2(d.r) + g)/(2*g);
    auto mu = sqrt(pow2(c.r)/g - pow2(eta));
    point q = c.p + eta*(d.p-c.p), v = mu*orth(d.p - c.p);
    return {q + v, q - v};
}

//-----------------------------------------------------------------------------
// intersection of line and circle
//-----------------------------------------------------------------------------
vector<point> intersect(line l, circle c) {
    point u = l.q - l.p, v = l.p - c.p;
    auto a = dot(u,u), b = dot(u,v)/a, t = (dot(v,v) - c.r*c.r)/a;
    auto det = b*b - t;
    if (det <  - EPS * EPS) return {};                    // no solution
    if (det < EPS * EPS) return {l.p - b*u}; // touch inner/outer
    return {l.p - (b + sqrt(det))*u,                // properly intersect
                    l.p - (b - sqrt(det))*u};
}
vector<point> intersect(circle c, line l) {
    return intersect(l, c);
}

bool contains(circle c, point p) {
    return sign(dot(c.p-p, c.p-p) - c.r * c.r) <= 0;
}

const int N = 50005;

line L[N];

int main(){
	int n;
	scanf("%d", &n);
	point p;
	int xp, yp, m;
	scanf("%d %d %d", &xp, &yp, &m);
	point center = {xp / 1000., yp / 1000.};
	for(int i = 1; i <= n; i++){
		int a, b;
		scanf("%d %d", &a,  &b);
		L[i] = {{0., (b) / 1000.}, {1., (a + b) / 1000.}};
	}
	double answer = 0;
	function<long long(double, bool findIntersections)> countIntersections = [&](double r, bool calc){
		vector< pair<point, int> > intersections;
		circle C = {center, r};
		for(int i = 1; i <= n; i++){
			vector<point> pts = intersect(L[i], C);
			if((int)pts.size() >= 2){
				intersections.push_back({pts[0] - center, i});
				intersections.push_back({pts[1] - center, i});	
			}
		}
		sort(intersections.begin(), intersections.end(), [&](const pair<point, int> & p, const pair<point, int> & q){
			return polar_angle()(p.fst, q.fst);
		});
		vector<int> where(n + 1, 0);
		vector<int> ind(2 * n + 1, 0);
		ordered_set os;
		int iter = 0;
		long long count = 0;
		for(auto p : intersections){
			if(where[p.snd]){
				count += os.size() - os.order_of_key(where[p.snd]) - 1;
				if(calc){
					auto it = os.upper_bound(where[p.snd]);
					while(it != os.end()){
						answer += dist(center, intersect(L[p.snd], L[ind[*it]])[0]);
						it++;
					}
				}
				os.erase(where[p.snd]);

			} else{
				where[p.snd] = iter;
				ind[iter] = p.snd;
				os.insert(iter);
			}
			iter++;
		}
		return count;
	};
	double lo = 0, hi = 2e9;
	while(hi - lo > EPS){
		double r = (lo + hi) / 2.;
		if(countIntersections(r, 0) >= m) hi = r;
		else{
			lo = r;
		}
	}
	long long num = countIntersections(lo, 1);
	if(num < m){
		answer += lo * (m 	- num);
	}
	if(num > m){
		answer -= lo * (m - num);
	}
	if(lo < 1e-7) answer = 0;
	printf("%.10lf\n", answer);
}