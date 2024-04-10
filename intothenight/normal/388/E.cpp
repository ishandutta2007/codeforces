#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }

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
#define compareop(op) bool operator op(const point &otr) const{ return pair(x, y) op pair(otr.x, otr.y); }
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
template<class T>
struct line{
	point<T> p{}, d{}; // p + d*t
	line(){ }
	line(point<T> p, point<T> q, bool Two_Points = true): p(p), d(Two_Points ? q - p : q){ }
	line(point<T> d): p(), d(static_cast<point<T>>(d)){ }
	line(T a, T b, T c): p(a ? -c / a : 0, !a && b ? -c / b : 0), d(-b, a){ }
	template<class U> explicit operator line<U>() const{
		return line<U>(point<U>(p), point<U>(d), false);
	}
	point<T> q() const{
		return p + d;
	}
	operator bool() const{
		return d.x != 0 || d.y != 0;
	}
	tuple<T, T, T> coef() const{
		return {d.y, -d.x, d.perp() * p};
	} // d.y (X - p.x) - d.x (Y - p.y) = 0
	bool operator||(const line<T> &L) const{
		return d || L.d;
	}
	line translate(T x) const{
		auto dir = d.perp();
		return {p + dir.unit() * x, d, false};
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

template<class T>
struct point3{
	T x{}, y{}, z{};
	point3(){ }
	template<class U> point3(const point3<U> &otr): x(otr.x), y(otr.y), z(otr.z){ }
	template<class U, class V, class W> point3(U x, V y, W z): x(x), y(y), z(z){ }
	template<class U> explicit operator point3<U>() const{
		return point3<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z));
	}
	T operator*(const point3 &otr) const{
		return x * otr.x + y * otr.y + z * otr.z;
	}
	point3 operator^(const point3 &otr) const{
		return {y * otr.z - z * otr.y, z * otr.x - x * otr.z, x * otr.y - y * otr.x};
	}
	point3 operator+(const point3 &otr) const{
		return {x + otr.x, y + otr.y, z + otr.z};
	}
	point3 &operator+=(const point3 &otr){
		return *this = *this + otr;
	}
	point3 operator-(const point3 &otr) const{
		return {x - otr.x, y - otr.y, z - otr.z};
	}
	point3 &operator-=(const point3 &otr){
		return *this = *this - otr;
	}
	point3 operator-() const{
		return {-x, -y, -z};
	}
#define scalarop_l(op) friend point3 operator op(const T &c, const point3 &p){ return {c op p.x, c op p.y, c op p.z}; }
	scalarop_l(+) scalarop_l(-) scalarop_l(*) scalarop_l(/)
#define scalarop_r(op) point3 operator op(const T &c) const{ return {x op c, y op c, z op c}; }
	scalarop_r(+) scalarop_r(-) scalarop_r(*) scalarop_r(/)
#define scalarapply(op) point3 &operator op(const T &c){ return *this = *this op c; }
	scalarapply(+=) scalarapply(-=) scalarapply(*=) scalarapply(/=)
#define compareop(op) bool operator op(const point3 &otr) const{ return tuple(x, y, z) op tuple(otr.x, otr.y, otr.z); }
	compareop(>) compareop(<) compareop(>=) compareop(<=) compareop(==) compareop(!=)
#undef scalarop_l
#undef scalarop_r
#undef scalarapply
#undef compareop
	double norm() const{
		return sqrt(x * x + y * y + z * z);
	}
	T squared_norm() const{
		return x * x + y * y + z * z;
	}
	point3<double> unit() const{
		return point3<double>(x, y, z) / norm();
	}
	point3 reflect_x() const{
		return {x, -y, -z};
	}
	point3 reflect_y() const{
		return {-x, y, -z};
	}
	point3 reflect_z() const{
		return {-x, -y, z};
	}
	point3 reflect_xy() const{
		return {x, y, -z};
	}
	point3 reflect_yz() const{
		return {-x, y, z};
	}
	point3 reflect_zx() const{
		return {x, -y, z};
	}
	point3 reflect(const point3 &o = {}) const{
		return {2 * o.x - x, 2 * o.y - y, 2 * o.z - z};
	}
	bool operator||(const point3 &otr) const{
		auto d = *this ^ otr;
		return abs(d.x) <= 1e-9 && abs(d.y) <= 1e-9 && abs(d.z) <= 1e-9;
	}
};
template<class T> istream &operator>>(istream &in, point3<T> &p){
	return in >> p.x >> p.y >> p.z;
}
template<class T> ostream &operator<<(ostream &out, const point3<T> &p){
	return out << "{" << p.x << ", " << p.y << ", " << p.z << "}";
}
template<class T>
double distance(const point3<T> &p, const point3<T> &q){
	return (p - q).norm();
}
template<class T>
T squared_distance(const point3<T> &p, const point3<T> &q){
	return (p - q).squared_norm();
}
template<class T>
double angle(const point3<T> &p, const point3<T> &q){
	return atan2((p ^ q).norm(), p * q);
}

using point3int = point3<int>;
using point3ll = point3<long long>;
using point3lll = point3<__int128_t>;
using point3d = point3<double>;
using point3ld = point3<long double>;

// Requires point3
template<class T>
struct line3{
	point3<T> p{}, d{}; // p + d*t
	line3(){ }
	line3(point3<T> p, point3<T> q, bool Two_point3s = true): p(p), d(Two_point3s ? q - p : q){ }
	line3(point3<T> d): p(), d(static_cast<point3<T>>(d)){ }
	template<class U> explicit operator line3<U>() const{
		return line3<U>(point3<U>(p), point3<U>(d), false);
	}
	point3<T> q() const{
		return p + d;
	}
	operator bool() const{
		return abs(d.x) > 1e-9 || abs(d.y) > 1e-9 || abs(d.z) > 1e-9;
	}
	bool operator||(const line3<T> &L) const{
		return d || L.d;
	}
};
template<class T> istream &operator>>(istream &in, line3<T> &l){
	in >> l.p >> l.d, l.d -= l.p;
	return in;
}
template<class T> ostream &operator<<(ostream &out, const line3<T> &l){
	return out << "{" << l.p << " -> " << l.q() << "}";
}
template<class T>
bool coplanar(const line3<T> &L, const line3<T> &M){
	return (L.d || M.d) || abs((L.p - M.p) * (L.d ^ M.d)) <= 1e-9;
}
template<class T>
bool on_line3(const point3<T> &p, const line3<T> &L){
	return L ? p - L.p || L.d : p == L.p;
}
template<class T>
bool on_ray(const point3<T> &p, const line3<T> &L){
	return L ? (L.p - p || L.q() - p) && (L.p - p) * L.d <= 0 : p == L.p;
}
template<class T>
bool on_segment(const point3<T> &p, const line3<T> &L){
	return L ? (L.p - p || L.q() - p) && (L.p - p) * (L.q() - p) <= 0 : p == L.p;
}
template<class T>
bool on_open_segment(const point3<T> &p, const line3<T> &L){
	return L ? (L.p - p || L.q() - p) && (L.p - p) * (L.q() - p) < 0 : p == L.p;
}
template<class T>
double distance_to_line(const point3<T> &p, const line3<T> &L){
	return L ? (p - L.p ^ L.d).norm() / L.d.norm() : distance(p, L.p);
}
template<class T>
double distance_to_ray(const point3<T> &p, const line3<T> &L){
	return (p - L.p) * L.d <= 0 ? distance(p, L.p) : distance_to_line(p, L);
}
template<class T>
double distance_to_segment(const point3<T> &p, const line3<T> &L){
	return (p - L.p) * L.d <= 0 ? distance(p, L.p) : (p - L.q()) * L.d >= 0 ? distance(p, L.q()) : distance_to_line3(p, L);
}
template<class T>
point3<double> projection(const point3<T> &p, const line3<T> &L){
	return static_cast<point3<double>>(L.p) + (L ? (p - L.p) * L.d / L.d.squared_norm() * static_cast<point3<double>>(L.d) : point3<double>());
}
template<class T>
point3<double> reflection(const point3<T> &p, const line3<T> &L){
	return 2.0 * projection(p, L) - static_cast<point3<double>>(p);
}
template<class T>
point3<double> closest_point_on_segment(const point3<T> &p, const line3<T> &L){
	return (p - L.p) * L.d <= 0 ? static_cast<point3<double>>(L.p) : ((p - L.q()) * L.d >= 0 ? static_cast<point3<double>>(L.q()) : projection(p, L));
}

using line3int = line3<int>;
using line3ll = line3<long long>;
using line3lll = line3<__int128_t>;
using line3d = line3<double>;
using line3ld = line3<long double>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<line3ll> a(n);
	vector<line3ld> da(n);
	auto normalize = [&](point3ll &d)->void{
		if(d.x < 0 || d.x == 0 && d.y < 0 || d.x == 0 && d.y == 0 && d.z < 0){
			d = -d;
		}
		auto g = gcd(gcd(d.x, d.y), d.z);
		d.x /= g, d.y /= g, d.z /= g;
	};
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		normalize(a[i].d);
		da[i] = line3ld(a[i]);
	}
	auto intersection = [&](int i, int j)->point3ld{
		long double low = -1e6, high = 1e6;
		for(auto rep = 200; rep; -- rep){
			long double mid1 = (low * 2 + high) / 3;
			long double mid2 = (low + high * 2) / 3;
			if(distance_to_line(da[i].p + mid1 * da[i].d, da[j]) <= distance_to_line(da[i].p + mid2 * da[i].d, da[j])){
				high = mid2;
			}
			else{
				low = mid1;
			}
		}
		return da[i].p + (low + high) / 2 * da[i].d;
	};
	map<pair<point3ll, long long>, pair<int, map<point3ll, int>>> same_plane;
	vector<point3ld> same_point;
	int res = 1;
	for(auto i = 0; i < n; ++ i){
		for(auto j = i + 1; j < n; ++ j){
			if(a[i].d == a[j].d){
				auto dir = a[i].d ^ (a[i].p - a[j].p);
				normalize(dir);
				auto &cur = same_plane[{dir, a[i].p * dir}];
				++ cur.first;
				++ cur.second[a[i].d];
			}
			else if(coplanar(a[i], a[j])){
				// non-parallel & same plane
				auto dir = a[i].d ^ a[j].d;
				normalize(dir);
				auto &cur = same_plane[{dir, a[i].p * dir}];
				++ cur.first;
				same_point.push_back(intersection(i, j));
			}
		}
	}
	// find y such that y(y+1)/2 == x
	// y^2 + y - 2x = 0
	// y = 1/2 * (-1 +- sqrt(1 + 8x))
	auto recover = [&](int x)->int{
		int y = (sqrt(8 * x) - 1) / 2;
		while(y * (y + 1) / 2 < x){
			++ y;
		}
		assert(y * (y + 1) / 2 == x);
		return y;
	};
	for(auto &[plane, data]: same_plane){
		int cur = recover(data.first) + 1;
		for(auto [dir, cnt]: data.second){
			cur -= recover(cnt);
		}
		ctmax(res, cur);
	}
	ranges::sort(same_point, [&](auto p, auto q){
		if(abs(p.x - q.x) > 1e-9){
			return p.x < q.x;
		}
		else if(abs(p.y - q.y) > 1e-9){
			return p.y < q.y;
		}
		else{
			return p.z < q.z;
		}
	});
	for(auto l = 0; l < (int)same_point.size(); ){
		int r = l;
		while(r < (int)same_point.size() && abs(same_point[l].x - same_point[r].x) <= 1e-9 && abs(same_point[l].y - same_point[r].y) <= 1e-9 && abs(same_point[l].z - same_point[r].z) <= 1e-9){
			++ r;
		}
		ctmax(res, recover(r - l) + 1);
		l = r;
	}
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