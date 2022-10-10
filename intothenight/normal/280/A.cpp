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
	template<class U> point(const array<U, 2> &p): x(p[0]), y(p[1]){ }
	template<class U> operator array<U, 2>() const{
		return {x, y};
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
		return hypot(x, y);
	}
	long double norml() const{
		return hypotl(x, y);
	}
	T squared_norm() const{
		return x * x + y * y;
	}
	// [-pi, pi]
	double angle() const{
		return atan2(y, x);
	}
	// [-pi, pi]
	long double anglel() const{
		return atan2l(y, x);
	}
	point<double> unit() const{
		return point<double>(x, y) / norm();
	}
	point<long double> unitl() const{
		return point<long double>(x, y) / norml();
	}
	point perp() const{
		return {-y, x};
	}
	point<double> normal() const{
		return perp().unit();
	}
	point<long double> normall() const{
		return perp().unitl();
	}
	point<double> rotate(double theta) const{
		return {x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)};
	}
	point<long double> rotatel(double theta) const{
		return {x * cosl(theta) - y * sinl(theta), x * sinl(theta) + y * cosl(theta)};
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
long double distancel(const point<T> &p, const point<T> &q){
	return (p - q).norml();
}
template<class T>
T squared_distance(const point<T> &p, const point<T> &q){
	return (p - q).squared_norm();
}
template<class T>
T doubled_signed_area(const point<T> &p, const point<T> &q, const point<T> &r){
	return q - p ^ r - p;
}
template<class T>
T doubled_signed_area(const vector<point<T>> &a){
	if(a.empty()) return 0;
	T res = a.back() ^ a.front();
	for(auto i = 1; i < (int)a.size(); ++ i) res += a[i - 1] ^ a[i];
	return res;
}
// [-pi, pi]
template<class T>
double angle(const point<T> &p, const point<T> &q){
	return atan2(p ^ q, p * q);
}
// [-pi, pi]
template<class T>
long double anglel(const point<T> &p, const point<T> &q){
	return atan2l(p ^ q, p * q);
}
// Check if p->q->r is sorted by angle with respect to the origin
template<class T>
bool is_sorted_by_angle(const point<T> &origin, const point<T> &p, const point<T> &q, const point<T> &r){
	T x = p - origin ^ q - origin;
	T y = q - origin ^ r - origin;
	if(x >= 0 && y >= 0) return true;
	if(x < 0 && y < 0) return false;
	return (p - origin ^ r - origin) < 0;
}
// Check if a is sorted by angle with respect to the origin
template<class T>
bool is_sorted_by_angle(const point<T> &origin, const vector<point<T>> &a){
	for(auto i = 0; i < (int)a.size() - 2; ++ i) if(!is_sorted_by_angle(origin, a[i], a[i + 1], a[i + 2])) return false;
	return true;
}
template<class T>
bool counterclockwise(const point<T> &p, const point<T> &q, const point<T> &r){
	return doubled_signed_area(p, q, r) > 0;
}
template<class T>
bool clockwise(const point<T> &p, const point<T> &q, const point<T> &r){
	return doubled_signed_area(p, q, r) < 0;
}
template<class T>
bool colinear(const point<T> &p, const point<T> &q, const point<T> &r){
	return doubled_signed_area(p, q, r) == 0;
}
template<class T>
bool colinear(const vector<point<T>> &a){
	int i = 1;
	while(i < (int)a.size() && a[0] == a[i]) ++ i;
	if(i >= (int)a.size()) return true;
	for(auto j = i + 1; j < (int)a.size(); ++ j) if(!colinear(a[0], a[i], a[j])) return false;
	return true;
}

using pointint = point<int>;
using pointll = point<long long>;
using pointlll = point<__int128_t>;
using pointd = point<double>;
using pointld = point<long double>;

// Requires point
template<class T>
struct line{
	point<T> p{}, d{}; // p + d*t
	line(){ }
	line(const line &l): p(l.p), d(l.d){ }
	template<class U, class V>
	line(const point<U> &p, const point<V> &q, bool Two_Points = true): p(p), d(Two_Points ? q - p : q){ }
	line(const point<T> &d): p(), d(d){ }
	line(T a, T b, T c): p(a ? -c / a : 0, !a && b ? -c / b : 0), d(-b, a){ }
	point<T> q() const{
		return p + d;
	}
	operator bool() const{
		return abs(d.x) > 1e-9 || abs(d.y) > 1e-9;
	}
	// d.y * (X - p.x) - d.x * (Y - p.y) = 0
	tuple<T, T, T> coef() const{
		return {d.y, -d.x, d.perp() * p};
	}
	bool operator||(const line<T> &L) const{
		return d || L.d;
	}
	line<double> translate(T x) const{
		auto dir = d.perp();
		return {point<double>(p) + dir.unit() * x, d, false};
	}
	line<long double> translatel(T x) const{
		auto dir = d.perp();
		return {point<long double>(p) + dir.unitl() * x, d, false};
	}
};
template<class T> istream &operator>>(istream &in, line<T> &l){
	in >> l.p >> l.d, l.d -= l.p;
	return in;
}
template<class T> ostream &operator<<(ostream &out, const line<T> &l){
	return out << "{" << l.p << " -> " << l.q() << "}";
}
template<class T>
bool on_line(const point<T> &p, const line<T> &L){
	return L ? p - L.p || L.d : p == L.p;
}
template<class T>
bool on_ray(const point<T> &p, const line<T> &L){
	return L ? (L.p - p || L.q() - p) && (L.p - p) * L.d <= 0 : p == L.p;
}
template<class T>
bool on_segment(const point<T> &p, const line<T> &L){
	return L ? (L.p - p || L.q() - p) && (L.p - p) * (L.q() - p) <= 0 : p == L.p;
}
template<class T>
bool on_open_segment(const point<T> &p, const line<T> &L){
	return L ? (L.p - p || L.q() - p) && (L.p - p) * (L.q() - p) < 0 : p == L.p;
}
template<class T>
double distance_to_line(const point<T> &p, const line<T> &L){
	return L ? abs(p - L.p ^ L.d) / L.d.norm() : distance(p, L.p);
}
template<class T>
long double distance_to_linel(const point<T> &p, const line<T> &L){
	return L ? abs(p - L.p ^ L.d) / L.d.norml() : distancel(p, L.p);
}
template<class T>
double distance_to_ray(const point<T> &p, const line<T> &L){
	return (p - L.p) * L.d <= 0 ? distance(p, L.p) : distance_to_line(p, L);
}
template<class T>
long double distance_to_rayl(const point<T> &p, const line<T> &L){
	return (p - L.p) * L.d <= 0 ? distancel(p, L.p) : distance_to_linel(p, L);
}
template<class T>
double distance_to_segment(const point<T> &p, const line<T> &L){
	return (p - L.p) * L.d <= 0 ? distance(p, L.p) : (p - L.q()) * L.d >= 0 ? distance(p, L.q()) : distance_to_line(p, L);
}
template<class T>
long double distance_to_segmentl(const point<T> &p, const line<T> &L){
	return (p - L.p) * L.d <= 0 ? distancel(p, L.p) : (p - L.q()) * L.d >= 0 ? distancel(p, L.q()) : distance_to_linel(p, L);
}
template<class T>
point<double> projection(const point<T> &p, const line<T> &L){
	return static_cast<point<double>>(L.p) + (L ? (p - L.p) * L.d / L.d.squared_norm() * point<double>(L.d) : point<double>());
}
template<class T>
point<long double> projectionl(const point<T> &p, const line<T> &L){
	return point<long double>(L.p) + (L ? (p - L.p) * L.d / L.d.squared_norml() * point<long double>(L.d) : point<long double>());
}
template<class T>
point<double> reflection(const point<T> &p, const line<T> &L){
	return 2.0 * projection(p, L) - point<double>(p);
}
template<class T>
point<long double> reflectionl(const point<T> &p, const line<T> &L){
	return 2.0l * projectionl(p, L) - point<long double>(p);
}
template<class T>
point<double> closest_point_on_segment(const point<T> &p, const line<T> &L){
	return (p - L.p) * L.d <= 0 ? point<double>(L.p) : ((p - L.q()) * L.d >= 0 ? point<double>(L.q()) : projection(p, L));
}
template<class T>
point<double> closest_point_on_segmentl(const point<T> &p, const line<T> &L){
	return (p - L.p) * L.d <= 0 ? point<long double>(L.p) : ((p - L.q()) * L.d >= 0 ? point<long double>(L.q()) : projectionl(p, L));
}

using lineint = line<int>;
using linell = line<long long>;
using linelll = line<__int128_t>;
using lined = line<double>;
using lineld = line<long double>;


// Requires point and line
template<int TYPE>
struct EndpointChecker{ };
// For rays
template<>
struct EndpointChecker<0>{
	template<class T>
	bool operator()(const T& a, const T& b) const{
		return true;
	}
};
// For closed end
template<>
struct EndpointChecker<1>{
	template<class T>
	bool operator()(const T& a, const T& b) const{
		return a <= b;
	}
};
// For open end
template<>
struct EndpointChecker<2>{
	template<class T>
	bool operator()(const T& a, const T& b) const{
		return a < b;
	}
};
// Assumes parallel lines do not intersect
template<int LA, int LB, int RA, int RB, class T>
optional<point<double>> intersect_no_parallel_overlap(const line<T> &L, const line<T> &M){
	auto s = L.d ^ M.d;
	if(s == 0) return {};
	auto ls = M.p - L.p ^ M.d, rs = M.p - L.p ^ L.d;
	if(s < 0) s = -s, ls = -ls, rs = -rs;
	if(EndpointChecker<LA>()(decltype(ls)(0), ls) && EndpointChecker<LB>()(ls, s) &&
	EndpointChecker<RA>()(decltype(rs)(0), rs) && EndpointChecker<RB>()(rs, s)){
		return static_cast<point<double>>(L.p) + 1.0 * ls / s * static_cast<point<double>>(L.d);
	}
	else return {};
}
// Assumes parallel lines do not intersect
template<class T>
optional<point<double>> intersect_closed_segments_no_parallel_overlap(const line<T> &L, const line<T> &M){
	return intersect_no_parallel_overlap<1, 1, 1, 1>(L, M);
}
// Assumes nothing
template<class T>
optional<line<double>> intersect_closed_segments(const line<T> &L, const line<T> &M){
	auto s = L.d ^ M.d, ls = M.p - L.p ^ M.d;
	if(!s){
		if(ls) return {};
		auto Lp = L.p, Lq = L.q(), Mp = M.p, Mq = M.q();
		if(Lp > Lq) swap(Lp, Lq);
		if(Mp > Mq) swap(Mp, Mq);
		line<T> res(max(Lp, Mp), min(Lq, Mq));
		if(res.d >= point<T>()) return static_cast<line<double>>(res);
		return {};
	}
	auto rs = M.p - L.p ^ L.d;
	if(s < 0) s = -s, ls = -ls, rs = -rs;
	if(0 <= ls && ls <= s && 0 <= rs && rs <= s) return line<double>(static_cast<point<double>>(L.p) + 1.0 * ls / s * static_cast<point<double>>(L.d), point<double>());
	else return {};
}
// Assumes nothing
template<class T>
optional<line<double>> intersect_open_segments(const line<T> &L, const line<T> &M){
	auto s = L.d ^ M.d, ls = M.p - L.p ^ M.d;
	if(!s){
		if(ls) return {};
		auto Lp = L.p, Lq = L.q(), Mp = M.p, Mq = M.q();
		if(Lp > Lq) swap(Lp, Lq);
		if(Mp > Mq) swap(Mp, Mq);
		line<T> res(max(Lp, Mp), min(Lq, Mq));
		if(res.d > point<T>()) return static_cast<line<double>>(res);
		return {};
	}
	auto rs = (M.p - L.p) ^ L.d;
	if(s < 0) s = -s, ls = -ls, rs = -rs;
	if(0 < ls && ls < s && 0 < rs && rs < s) return line<double>(static_cast<point<double>>(L.p) + 1.0 * ls / s * static_cast<point<double>>(L.d), point<double>());
	else return {};
}

// Requires point
template<class P>
struct compare_by_angle{
	const P origin;
	compare_by_angle(const P &origin = P()): origin(origin){ }
	bool operator()(const P &p, const P &q) const{
		return doubled_signed_area(origin, p, q) > 0;
	}
};
template<class It, class P>
void sort_by_angle(It begin, It end, const P &origin){
	begin = partition(begin, end, [&origin](const decltype(*begin) &point){ return point == origin; });
	auto pivot = partition(begin, end, [&origin](const decltype(*begin) &point) { return point > origin; });
	compare_by_angle<P> cmp(origin);
	sort(begin, pivot, cmp), sort(pivot, end, cmp);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	long double w, h, a;
	cin >> w >> h >> a;
	if(a >= 90){
		a = 180 - a;
	}
	if(a == 0){
		cout << w * h << "\n";
		return 0;
	}
	if(a == 90){
		cout << min(w, h) * min(w, h) << "\n";
		return 0;
	}
	a *= acosl(-1) / 180;
	array<pointld, 4> p{{
		{w / 2, h / 2},
		{-w / 2, h / 2},
		{-w / 2, -h / 2},
		{w / 2, -h / 2}
	}};
	array<pointld, 4> q;
	for(auto i = 0; i < 4; ++ i){
		q[i] = p[i].rotatel(a);
	}
	vector<pointld> res;
	for(auto i = 0; i < 4; ++ i){
		lineld L{p[i], p[i + 1 & 3]};
		for(auto j = 0; j < 4; ++ j){
			lineld M{q[j], q[j + 1 & 3]};
			if(auto interptr = intersect_closed_segments_no_parallel_overlap(L, M)){
				res.push_back(*interptr);
			}
		}
	}
	sort_by_angle(res.begin(), res.end(), pointld{});
	cout << doubled_signed_area(res) / 2 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////