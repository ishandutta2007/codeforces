#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

template<class T>
struct point{
	T x{}, y{};
	point(){ }
	template<class U> point(const point<U> &otr): x(otr.x), y(otr.y){ }
	template<class U, class V> point(U x, V y): x(x), y(y){ }
	template<class U> explicit operator point<U>() const{ return point<U>(static_cast<U>(x), static_cast<U>(y)); }
	T operator*(const point &otr) const{ return x * otr.x + y * otr.y; }
	T operator^(const point &otr) const{ return x * otr.y - y * otr.x; }
	point operator+(const point &otr) const{ return {x + otr.x, y + otr.y}; }
	point &operator+=(const point &otr){ return *this = *this + otr; }
	point operator-(const point &otr) const{ return {x - otr.x, y - otr.y}; }
	point &operator-=(const point &otr){ return *this = *this - otr; }
	point operator-() const{ return {-x, -y}; }
#define scalarop_l(op) friend point operator op(const T &c, const point &p){ return {c op p.x, c op p.y}; }
	scalarop_l(+) scalarop_l(-) scalarop_l(*) scalarop_l(/)
#define scalarop_r(op) point operator op(const T &c) const{ return {x op c, y op c}; }
	scalarop_r(+) scalarop_r(-) scalarop_r(*) scalarop_r(/)
#define scalarapply(op) point &operator op(const T &c){ return *this = *this op c; }
	scalarapply(+=) scalarapply(-=) scalarapply(*=) scalarapply(/=)
#define compareop(op) bool operator op(const point &otr) const{ return tie(x, y) op tie(otr.x, otr.y); }
	compareop(>) compareop(<) compareop(>=) compareop(<=) compareop(==) compareop(!=)
#undef scalarop_l
#undef scalarop_r
#undef scalarapply
#undef compareop
	double norm() const{ return sqrt(x * x + y * y); }
	T squared_norm() const{ return x * x + y * y; }
	double angle() const{ return atan2(y, x); } // [-pi, pi]
	point<double> unit() const{ return point<double>(x, y) / norm(); }
	point perp() const{ return {-y, x}; }
	point<double> normal() const{ return perp().unit(); }
	point<double> rotate(const double &theta) const{ return point<double>(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)); }
	point reflect_x() const{ return {x, -y}; }
	point reflect_y() const{ return {-x, y}; }
	point reflect(const point &o) const{ return {2 * o.x - x, 2 * o.y - y}; }
	bool operator||(const point &otr) const{ return !(*this ^ otr); }
};
template<class T> istream &operator>>(istream &in, point<T> &p){ return in >> p.x >> p.y; }
template<class T> ostream &operator<<(ostream &out, const point<T> &p){ return out << "{" << p.x << ", " << p.y << "}"; }
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
	assert(!a.empty());
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
	line(point<T> p, point<T> q, bool Two_Points = true): p(p), d(Two_Points ? q - p : q){ }
	line(point<T> d): p(), d(static_cast<point<T>>(d)){ }
	line(T a, T b, T c): p(a ? -c / a : 0, !a && b ? -c / b : 0), d(-b, a){ }
	template<class U> explicit operator line<U>() const{ return line<U>(point<U>(p), point<U>(d), false); }
	point<T> q() const{ return p + d; }
	operator bool() const{ return d.x != 0 || d.y != 0; }
	tuple<T, T, T> coef() const{ return {d.y, -d.x, d.perp() * p}; } // d.y (X - p.x) - d.x (Y - p.y) = 0
	bool operator||(const line<T> &L) const{ return d || L.d; }
};
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
double distance_to_line(const point<T> &p, const line<T> &L){
	return L ? abs(p - L.p ^ L.d) / L.d.norm() : distance(p, L.p);
}
template<class T>
double distance_to_ray(const point<T> &p, const line<T> &L){
	return (p - L.p) * L.d <= 0 ? distance(p, L.p) : distance_to_line(p, L);
}
template<class T>
double distance_to_segment(const point<T> &p, const line<T> &L){
	return (p - L.p) * L.d <= 0 ? distance(p, L.p) : (p - L.q()) * L.d >= 0 ? distance(p, L.q()) : distance_to_line(p, L);
}
template<class T>
point<double> projection(const point<T> &p, const line<T> &L){
	return static_cast<point<double>>(L.p) + (L ? (p - L.p) * L.d / L.d.squared_norm() * static_cast<point<double>>(L.d) : point<double>());
}
template<class T>
point<double> reflection(const point<T> &p, const line<T> &L){
	return 2.0 * projection(p, L) - static_cast<point<double>>(p);
}
template<class T>
point<double> closest_point_on_segment(const point<T> &p, const line<T> &L){
	return (p - L.p) * L.d <= 0 ? static_cast<point<double>>(L.p) : ((p - L.q()) * L.d >= 0 ? static_cast<point<double>>(L.q()) : projection(p, L));
}

using lineint = line<int>;
using linell = line<long long>;
using linelll = line<__int128_t>;
using lined = line<double>;
using lineld = line<long double>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	int n;
	pointll p;
	cin >> n >> p;
	vector<pointll> a(n);
	double mx = 0;
	for(auto &x: a){
		cin >> x;
		ctmax(mx, distance(x, p));
	}
	double mn = numeric_limits<double>::max();
	for(auto i = 0; i < n; ++ i){
		ctmin(mn, distance_to_segment(p, line(a[i], a[(i + 1) % n])));
	}
	cout << (mx * mx - mn * mn) * acos(-1) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////