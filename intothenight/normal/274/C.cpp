#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct point{
	T x{}, y{};
	point(){ }
	template<class U> point(const point<U> &otr): x(otr.x), y(otr.y){ }
	template<class U, class V> point(U x, V y): x(x), y(y){ }
	template<class U> explicit operator point<U>() const{
		return point<U>(static_cast<U>(x), static_cast<U>(y));
	}
	T operator*(const point &otr) const{
		return x * otr.x + y * otr.y;
	}
	T operator^(const point &otr) const{
		return x * otr.y - y * otr.x;
	}
	point operator+(const point &otr) const{
		return {x + otr.x, y + otr.y};
	}
	point &operator+=(const point &otr){
		return *this = *this + otr;
	}
	point operator-(const point &otr) const{
		return {x - otr.x, y - otr.y};
	}
	point &operator-=(const point &otr){
		return *this = *this - otr;
	}
	point operator-() const{
		return {-x, -y};
	}
#define scalarop_l(op) friend point operator op(const T &c, const point &p){ return {c op p.x, c op p.y}; }
	scalarop_l(+) scalarop_l(-) scalarop_l(*) scalarop_l(/)
#define scalarop_r(op) point operator op(const T &c) const{ return {x op c, y op c}; }
	scalarop_r(+) scalarop_r(-) scalarop_r(*) scalarop_r(/)
#define scalarapply(op) point &operator op(const T &c){ return *this = *this op c; }
	scalarapply(+=) scalarapply(-=) scalarapply(*=) scalarapply(/=)
#define compareop(op) bool operator op(const point &otr) const{ return pair<T, T>(x, y) op pair<T, T>(otr.x, otr.y); }
	compareop(>) compareop(<) compareop(>=) compareop(<=) compareop(==) compareop(!=)
#undef scalarop_l
#undef scalarop_r
#undef scalarapply
#undef compareop
	double norm() const{
		return sqrt(x * x + y * y);
	}
	T squared_norm() const{
		return x * x + y * y;
	}
	double angle() const{
		return atan2(y, x);
	} // [-pi, pi]
	point<double> unit() const{
		return point<double>(x, y) / norm();
	}
	point perp() const{
		return {-y, x};
	}
	point<double> normal() const{
		return perp().unit();
	}
	point<double> rotate(const double &theta) const{
		return {x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)};
	}
	point reflect_x() const{
		return {x, -y};
	}
	point reflect_y() const{
		return {-x, y};
	}
	point reflect(const point &o = {}) const{
		return {2 * o.x - x, 2 * o.y - y};
	}
	bool operator||(const point &otr) const{
		return !(*this ^ otr);
	}
};
template<class T> istream &operator>>(istream &in, point<T> &p){
	return in >> p.x >> p.y;
}
template<class T> ostream &operator<<(ostream &out, const point<T> &p){
	return out << "{" << p.x << ", " << p.y << "}";
}
template<class T>
double distance(const point<T> &p, const point<T> &q){
	return (p - q).norm();
}
template<class T>
T squared_distance(const point<T> &p, const point<T> &q){
	return (p - q).squared_norm();
}
template<class T, class U, class V>
T doubled_signed_area(const point<T> &p, const point<U> &q, const point<V> &r){
	return q - p ^ r - p;
}
template<class T>
T doubled_signed_area(const vector<point<T>> &a){
	if(a.empty()){
		return 0;
	}
	int n = (int)a.size();
	T res = a.back() ^ a.front();
	for(auto i = 1; i < n; ++ i) res += a[i - 1] ^ a[i];
	return res;
}
template<class T>
double angle(const point<T> &p, const point<T> &q){
	return atan2(p ^ q, p * q);
}
template<class T>
bool is_sorted(const point<T> &origin, point<T> p, point<T> q, point<T> r){
	p -= origin, q -= origin, r -= origin;
	T x = p ^ r, y = p ^ q, z = q ^ r;
	return x >= 0 && y >= 0 && z >= 0 || x < 0 && (y >= 0 || z >= 0);
} // check if p->q->r is sorted with respect to the origin
template<class T, class IT>
bool is_sorted(const point<T> &origin, IT begin, IT end){
	for(auto i = 0; i < (int)(end - begin) - 2; ++ i) if(!is_sorted(origin, *(begin + i), *(begin + i + 1), *(begin + i + 2))) return false;
	return true;
} // check if begin->end is sorted with respect to the origin
template<class T>
bool counterclockwise(const point<T> &p, const point<T> &q, const point<T> &r){
	return doubled_signed_area(p, q, r) > 0;
}
template<class T>
bool clockwise(const point<T> &p, const point<T> &q, const point<T> &r){
	return doubled_signed_area(p, q, r) < 0;
}

using pointint = point<int>;
using pointll = point<long long>;
using pointlll = point<__int128_t>;
using pointd = point<double>;
using pointld = point<long double>;

// Requires point
#define T double
#define POINTS const point<T> &p, const point<T> &q, const point<T> &r
point<T> weighted_mean(POINTS, T a = 0.5, T b = 0.5, T c = 0.5){
	return (a * p + b * q + c * r) / (a + b + c);
}
point<T> circumcenter(POINTS){
	point<T> a = r - p, b = q - p;
	return p + (a * b.squared_norm() - b * a.squared_norm()).perp() / (2 * a ^ b);
}
T circumradius(POINTS){
	return (p - q).norm() * (q - r).norm() * (r - p).norm() / (2 * doubled_signed_area(p, q, r));
}
point<T> incenter(POINTS){
	return weighted_mean(p, q, r, (p - q).norm(), (q - r).norm(), (r - p).norm());
}
T inradius(POINTS){
	return doubled_signed_area(p, q, r) / ((p - q).norm() + (q - r).norm() + (r - p).norm());
}
point<T> orthocenter(POINTS){
	return weighted_mean(p, q, r, (q - p ^ r - p) / ((q - p) * (r - p)), (r - q ^ p - q) / ((r - q) * (p - q)), (p - r ^ q - r) / ((p - r) * (q - r)));
}
template<int i> point<T> excenter(POINTS){
	return weighted_mean(p, q, r, (i == 0 ? -1 : 1) * (p - q).norm(), (i == 1 ? -1 : 1) * (q - r).norm(), (i == 2 ? -1 : 1) * (r - p).norm());
}
template<int i> T exradius(POINTS){
	return doubled_signed_area(p, q, r) / ((i == 0 ? -1 : 1) * (p - q).norm() + (i == 1 ? -1 : 1) * (q - r).norm() + (i == 2 ? -1 : 1) * (r - p).norm());
}
#undef POINTS
#undef T

template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }

// http://www.sccg.sk/~samuelcik/dgs/quad_edge.pdf
struct quad_edge{
	int o = -1; // origin of the arc
	quad_edge *onext, *rot;
	bool mark = false;
	quad_edge(){ }
	quad_edge(int o): o(o){ }
	int d(){ return sym()->o; } // destination of the arc
	quad_edge *sym(){ return rot->rot; }
	quad_edge *oprev(){ return rot->onext->rot; }
	quad_edge *lnext(){ return sym()->oprev(); }
};
quad_edge *make_sphere(int a, int b){
	array<quad_edge *, 4> q{{new quad_edge{a}, new quad_edge{}, new quad_edge{b}, new quad_edge{}}};
	for(auto i = 0; i < 4; ++ i) q[i]->onext = q[-i & 3], q[i]->rot = q[i + 1 & 3];
	return q[0];
}
void splice(quad_edge *a, quad_edge *b){
	swap(a->onext->rot->onext, b->onext->rot->onext);
	swap(a->onext, b->onext);
}
quad_edge *connect(quad_edge *a, quad_edge *b){
	quad_edge *q = make_sphere(a->d(), b->o);
	splice(q, a->lnext()), splice(q->sym(), b);
	return q;
}

// T_large must be able to hold O(T^4), can be long long if coord <= 2e4
// Assumes no duplicate points
// O(n log n)
// Requires point and quad_edge
template<class T, class F1, class F2, class T_large = __int128_t>
bool delaunay_triangulation(const vector<point<T>> &a, F1 process_outer_face, F2 process_triangles){
	int n = (int)a.size();
	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int i, int j){ return a[i] < a[j]; });
	assert(unique(ind.begin(), ind.end(), [&](int i, int j){ return a[i] == a[j]; }) == ind.end());
	if(n < 2) return {};
	auto in_circle = [&](point<T> p, point<T> a, point<T> b, point<T> c){
		a -= p, b -= p, c -= p;
		return ((T_large)a.squared_norm() * (b ^ c) + (T_large)b.squared_norm() * (c ^ a) + (T_large)c.squared_norm() * (a ^ b)) * (doubled_signed_area(a, b, c) > 0 ? 1 : -1) > 0;
	};
	auto recurse = [&](int l, int r, auto recurse)->pair<quad_edge *, quad_edge *>{
		if(r - l <= 3){
			quad_edge *p = make_sphere(ind[l], ind[l + 1]);
			if(r - l == 2) return {p, p->sym()};
			quad_edge *q = make_sphere(ind[l + 1], ind[l + 2]);
			splice(p->sym(), q);
			auto side = doubled_signed_area(a[ind[l]], a[ind[l + 1]], a[ind[l + 2]]);
			quad_edge *c = side ? connect(q, p) : NULL;
			return {side < 0 ? c->sym() : p, side < 0 ? c : q->sym()};
		}
		int m = l + (r - l >> 1);
		auto [ra, A] = recurse(l, m, recurse);
		auto [B, rb] = recurse(m, r, recurse);
		while((doubled_signed_area(a[B->o], a[A->d()], a[A->o]) < 0 && (A = A->lnext())) || (doubled_signed_area(a[A->o], a[B->d()], a[B->o]) > 0 && (B = B->sym()->onext)));
		quad_edge *base = connect(B->sym(), A);
		if(A->o == ra->o) ra = base->sym();
		if(B->o == rb->o) rb = base;
#define valid(e) (doubled_signed_area(a[e->d()], a[base->d()], a[base->o]) > 0)
#define DEL(e, init, dir) \
quad_edge *e = init->dir; \
if(valid(e)) while(in_circle(a[e->dir->d()], a[base->d()], a[base->o], a[e->d()])){ \
	quad_edge *t = e->dir; \
	splice(e, e->oprev()); \
	splice(e->sym(), e->sym()->oprev()); \
	delete e->rot->rot->rot, delete e->rot->rot, delete e->rot, delete e; \
	e = t; \
}
		while(true){
			DEL(LC, base->sym(), onext);
			DEL(RC, base, oprev());
			if(!valid(LC) && !valid(RC)) break;
			if(!valid(LC) || (valid(RC) && in_circle(a[RC->d()], a[RC->o], a[LC->d()], a[LC->o]))) base = connect(RC, base->sym());
			else base = connect(base->sym(), LC->sym());
		}
		return {ra, rb};
	};
	auto e = recurse(0, n, recurse).first;
	vector<quad_edge *> q = {e}, rem; q.reserve(3 * n), rem.reserve(3 * n);
	while(doubled_signed_area(a[e->onext->d()], a[e->d()], a[e->o]) < 0) e = e->onext;
	vector<int> face; face.reserve(n);
	bool colinear = false;
#define ADD \
{ \
	quad_edge *c = e; \
	face.clear(); \
	do{ \
		c->mark = true; \
		face.push_back(c->o); \
		q.push_back(c->sym()); \
		rem.push_back(c); \
		c = c->lnext(); \
	}while(c != e); \
}
	ADD;
	process_outer_face(face);
	for(auto qi = 0; qi < (int)q.size(); ++ qi){
		if(!(e = q[qi])->mark){
			ADD;
			colinear = false;
			process_triangles(face[0], face[1], face[2]);
		}
	}
	for(auto e: rem) delete e->rot, delete e;
	return !colinear;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<point<int>> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	bool any = false;
	double res = numeric_limits<double>::min();
	vector<vector<int>> isouter(n, vector<int>(n));
	delaunay_triangulation(a, [&](const vector<int> &outer){
		for(auto t = 0; t < (int)outer.size(); ++ t){
			int i = outer[t], j = outer[(t + 1) % (int)outer.size()];
			isouter[i][j] = isouter[j][i] = true;
		}
	},
	[&](int i, int j, int k){
		if((a[j] - a[i]) * (a[k] - a[j]) <= 0 && (a[k] - a[j]) * (a[i] - a[k]) <= 0 && (a[i] - a[k]) * (a[j] - a[i]) <= 0){
			if((a[j] - a[i]) * (a[k] - a[j]) == 0){
				if(!isouter[k][i]){
					any = true;
					ctmax(res, distance(a[k], a[i]) / 2);
				}
			}
			else if((a[k] - a[j]) * (a[i] - a[k]) == 0){
				if(!isouter[i][j]){
					any = true;
					ctmax(res, distance(a[i], a[j]) / 2);
				}
			}
			else if((a[i] - a[k]) * (a[j] - a[i]) == 0){
				if(!isouter[j][k]){
					any = true;
					ctmax(res, distance(a[j], a[k]) / 2);
				}
			}
			else{
				any = true;
				ctmax(res, circumradius(a[i], a[j], a[k]));
			}
		}
	});
	if(!any){
		cout << "-1\n";
		return 0;
	}
	cout << fixed << setprecision(15);
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////