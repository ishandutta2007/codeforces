#include <bits/stdc++.h>
using namespace std;

template<class T>
struct point{
	T x, y;
	template<class U> point(const point<U> &otr): x(otr.x), y(otr.y){ }
	template<class U = T, class V = T> point(U x = 0, V y = 0): x(x), y(y){ }
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
	double arg() const{ return atan2(y, x); } // [-pi, pi]
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
template<class T> ostream &operator<<(ostream &out, const point<T> &p){ return out << "(" << p.x << ", " << p.y << ")"; }
template<class T>
double distance(const point<T> &p, const point<T> &q){
	return (p - q).norm();
}
template<class T>
T squared_distance(const point<T> &p, const point<T> &q){
	return (p - q).squared_norm();
}
template<class T, class U, class V>
T ori(const point<T> &p, const point<U> &q, const point<V> &r){
	return q - p ^ r - p;
}
template<class IT>
auto doubled_signed_area(IT begin, IT end){
	class iterator_traits<IT>::value_type s = 0, init = *begin;
	for(; begin != prev(end); ++ begin) s += *begin ^ *next(begin);
	return s + (*begin ^ init);
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

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<class T> ostream &operator<<(class enable_if<!is_same<T, string>::value, ostream>::type &out, const T &arr){
	out << "{"; for(auto x: arr) out << x << ", ";
	return out << (arr.empty() ? "" : "\b\b") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(auto i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "[" << #__VA_ARGS__ << "]", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	point<double> p, q, v, w;
	double vmax, t;
	cin >> p >> q >> vmax >> t >> v >> w;
	auto check1 = [&](double th){
		return th >= (q - (p + v * th)).norm() / vmax;
	};
	auto check2 = [&](double th){
		return th - t >= (q - (p + v * t + w * (th - t))).norm() / vmax - t;
	};
	if(check1(t)){
		double low = 0, high = t;
		for(auto rep = 0; rep < 200; ++ rep){
			double mid = (low + high) / 2;
			if(check1(mid)){
				high = mid;
			}
			else{
				low = mid;
			}
		}
		cout << (low + high) / 2 << "\n";
	}
	else{
		double low = t, high = 1e18;
		for(auto rep = 0; rep < 200; ++ rep){
			double mid = (low + high) / 2;
			if(check2(mid)){
				high = mid;
			}
			else{
				low = mid;
			}
		}
		cout << (low + high) / 2 << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////