#include <bits/stdc++.h>
using namespace std;

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
template<class T> ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "----DEBUG BEGIN----\n[" << #__VA_ARGS__ << "]:", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

template<class T> struct point{
	T x, y;
	int ind;
	template<class U> point(const point<U> &otr): x(otr.x), y(otr.y), ind(otr.ind){ }
	template<class U = T, class V = T> point(U x = 0, V y = 0, int ind = -1): x(x), y(y), ind(ind){ }
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
template<class T> double distance(const point<T> &p, const point<T> &q){ return (p - q).norm(); }
template<class T> T squared_distance(const point<T> &p, const point<T> &q){ return (p - q).squared_norm(); }
template<class T, class U, class V> T ori(const point<T> &p, const point<U> &q, const point<V> &r){ return (q - p) ^ (r - p); }
template<class IT> auto doubled_signed_area(IT begin, IT end){
	class iterator_traits<IT>::value_type s = 0, init = *begin;
	for(; begin != prev(end); ++ begin) s += *begin ^ *next(begin);
	return s + (*begin ^ init);
}
template<class T> bool is_sorted(const point<T> &origin, point<T> p, point<T> q, point<T> r){
	p -= origin, q -= origin, r -= origin;
	T x = p ^ r, y = p ^ q, z = q ^ r;
	return x >= 0 && y >= 0 && z >= 0 || x < 0 && (y >= 0 || z >= 0);
}
template<class T, class IT> bool is_sorted(const point<T> &origin, IT begin, IT end){
	for(int i = 0; i < end - begin - 2; ++ i) if(!is_sorted(origin, begin + i, begin + i + 1, begin + i + 2)) return false;
	return true;
}
template<class T = long long> struct line{
	point<T> p, d; // p + d*t
	template<class U = T, class V = T> line(point<U> p = {0, 0}, point<V> q = {0, 0}, bool Two_Points = true): p(p), d(Two_Points ? q - p : q){ }
	template<class U> line(point<U> d): p(), d(static_cast<point<T>>(d)){ }
	line(T a, T b, T c): p(a ? -c / a : 0, !a && b ? -c / b : 0), d(-b, a){ }
	template<class U> explicit operator line<U>() const{ return line<U>(point<U>(p), point<U>(d), false); }
	point<T> q() const{ return p + d; }
	bool degen() const{ return d == point<T>(); }
	tuple<T, T, T> coef() const{ return {d.y, -d.x, d.perp() * p}; } // d.y (X - p.x) - d.x (Y - p.y) = 0
	bool operator||(const line<T> &L) const{ return d || L.d; }
};
template<class T> bool on_line(const point<T> &p, const line<T> &L){
	if(L.degen()) return p == L.p;
	return (p - L.p) || L.d;
}
template<class T> bool on_ray(const point<T> &p, const line<T> &L){
	if(L.degen()) return p == L.p;
	auto a = L.p - p, b = L.q() - p;
	return (a || b) && a * L.d <= 0;
}
template<class T> bool on_segment(const point<T> &p, const line<T> &L){
	if(L.degen()) return p == L.p;
	auto a = L.p - p, b = L.q() - p;
	return (a || b) && a * b <= 0;
}
template<class T> double distance_to_line(const point<T> &p, const line<T> &L){
	if(L.degen()) return distance(p, L.p);
	return abs((p - L.p) ^ L.d) / L.d.norm();
}
template<class T> double distance_to_ray(const point<T> &p, const line<T> &L){
	if((p - L.p) * L.d <= 0) return distance(p, L.p);
	return distance_to_line(p, L);
}
template<class T> double distance_to_segment(const point<T> &p, const line<T> &L){
	if((p - L.p) * L.d <= 0) return distance(p, L.p);
	if((p - L.q()) * L.d >= 0) return distance(p, L.q());
	return distance_to_line(p, L);
}
template<class T> point<double> projection(const point<T> &p, const line<T> &L){ return static_cast<point<double>>(L.p) + (L.degen() ? point<double>() : (p - L.p) * L.d / L.d.norm() * static_cast<point<double>>(L.d)); }
template<class T> point<double> reflection(const point<T> &p, const line<T> &L){ return 2.0 * projection(p, L) - static_cast<point<double>>(p); }
template<class T> point<double> closest_point_on_segment(const point<T> &p, const line<T> &L){ return (p - L.p) * L.d <= 0 ? static_cast<point<double>>(L.p) : ((p - L.q()) * L.d >= 0 ? static_cast<point<double>>(L.q()) : projection(p, L)); }
template<int TYPE> struct EndpointChecker{ };
// For rays
template<> struct EndpointChecker<0>{ template<class T> bool operator()(const T& a, const T& b) const{ return true; } }; // For ray
// For closed end
template<> struct EndpointChecker<1>{ template<class T> bool operator()(const T& a, const T& b) const{ return a <= b; } }; // For closed end
// For open end
template<> struct EndpointChecker<2>{ template<class T> bool operator()(const T& a, const T& b) const{ return a < b; } }; // For open end
// Assumes parallel lines do not intersect
template<int LA, int LB, int RA, int RB, class T> pair<bool, point<double>> intersect_no_parallel_overlap(const line<T> &L, const line<T> &M){
	auto s = L.d ^ M.d;
	if(!s) return {false, point<double>()};
	auto ls = (M.p - L.p) ^ M.d, rs = (M.p - L.p) ^ L.d;
	if(s < 0) s = -s, ls = -ls, rs = -rs;
	bool intersect = EndpointChecker<LA>()(decltype(ls)(0), ls) && EndpointChecker<LB>()(ls, s) && EndpointChecker<RA>()(decltype(rs)(0), rs) && EndpointChecker<RB>()(rs, s);
	return {intersect, static_cast<point<double>>(L.p) + 1.0 * ls / s * static_cast<point<double>>(L.d)};
}
// Assumes parallel lines do not intersect
template<class T> pair<bool, point<double>> intersect_closed_segments_no_parallel_overlap(const line<T> &L, const line<T> &M){
	return intersect_no_parallel_overlap<1, 1, 1, 1>(L, M);
}
// Assumes nothing
template<class T> pair<bool, line<double>> intersect_closed_segments(const line<T> &L, const line<T> &M){
	auto s = L.d ^ M.d, ls = (M.p - L.p) ^ M.d;
	if(!s){
		if(ls) return {false, line<double>()};
		auto Lp = L.p, Lq = L.q(), Mp = M.p, Mq = M.q();
		if(Lp > Lq) swap(Lp, Lq);
		if(Mp > Mq) swap(Mp, Mq);
		line<double> res(max(Lp, Mp), min(Lq, Mq));
		return {res.d >= point<double>(), res};
	}
	auto rs = (M.p - L.p) ^ L.d;
	if(s < 0) s = -s, ls = -ls, rs = -rs;
	bool intersect = 0 <= ls && ls <= s && 0 <= rs && rs <= s;
	return {intersect, line<double>(static_cast<point<double>>(L.p) + 1.0 * ls / s * static_cast<point<double>>(L.d), point<double>())};
}
template<class T> double distance_between_rays(const line<T> &L, const line<T> &M){
	if(L || M){
		if(L.d * M.d >= 0 || (M.p - L.p) * M.d <= 0) return distance_to_line(L.p, M);
		else return distance(L.p, M.p);
	}
	else{
		if(intersect_no_parallel_overlap<1, 0, 1, 0, long long>(L, M).first) return 0;
		else return min(distance_to_ray(L.p, M), distance_to_ray(M.p, L));
	}
}
template<class T> double distance_between_segments(const line<T> &L, const line<T> &M){
	if(intersect_closed_segments(L, M).first) return 0;
	return min({distance_to_segment(L.p, M), distance_to_segment(L.q(), M), distance_to_segment(M.p, L), distance_to_segment(M.q(), L)});
}
template<class P> struct compare_by_angle{
	const P origin;
	compare_by_angle(const P &origin = P()): origin(origin){ }
	bool operator()(const P &p, const P &q) const{ return ori(origin, p, q) > 0; }
};
template<class It, class P> void sort_by_angle(It begin, It end, const P &origin){
	begin = partition(begin, end, [&origin](const decltype(*begin) &point){ return point == origin; });
	auto pivot = partition(begin, end, [&origin](const decltype(*begin) &point) { return point > origin; });
	compare_by_angle<P> cmp(origin);
	sort(begin, pivot, cmp), sort(pivot, end, cmp);
}
/* Short Descriptions
struct point{
	T x, y;
	int ind;
	double norm()
	T squared_norm()
	double arg()
	point<double> unit()
	point perp()
	point<double> normal()
	point<double> rotate(double theta)
	point reflect_x()
	point reflect_y()
	point reflect(point o)
	bool operator||(point otr)
};
double distance(point p, point q)
T squared_distance(point p, point q)
T ori(point p, point q, point r)
auto doubled_signed_area(IT begin, IT end)
bool is_sorted(point o, point p, point q, point r)
bool is_sorted(point o, IT begin, IT end)
struct line{
	point p, d; // p + d*t
	line(point p = {0, 0}, point<V> q = {0, 0}, bool Two_Points = true)
	// two_points: pass through p and q
	// else: pass through p, slope q
	line(point<U> d) // pass through origin, slope d
	line(T a, T b, T c) // declare with ax + by + c = 0
	point<T> q()
	bool degen()
	tuple<T, T, T> coef()// d.y (X - p.x) - d.x (Y - p.y) = 0
};
bool on_line(point, line)
bool on_ray(point, line)
bool on_segment(point, line)
double distance_to_line(point, line)
double distance_to_ray(point, line)
double distance_to_segment(point, line)
point<double> projection(point, line)
point<double> reflection(point, line)
point<double> closest_point_on_segment(point, line)
// Endpoints: (0: rays), (1: closed), (2: open)
// Assumes parallel lines do not intersect
pair<bool, point<double>> intersect_no_parallel_overlap<EP1, EP2, EP3, EP4>(line, line)
// Assumes parallel lines do not intersect
pair<bool, point<double>> intersect_closed_segments_no_parallel_overlap(line, line)
// Assumes nothing
pair<bool, line<double>> intersect_closed_segments(line, line)
double distance_between_rays(line, line)
double distance_between_segments(line, line)
struct compare_by_angle
void sort_by_angle(It begin, It end, const P &origin) */

template<class T, int type = 0>
struct convex_hull: pair<vector<point<T>>, vector<point<T>>>{ // (Lower, Upper) type {0: both, 1: lower, 2: upper}
	using pair<vector<point<T>>, vector<point<T>>>::first;
	using pair<vector<point<T>>, vector<point<T>>>::second;
	convex_hull(vector<point<T>> arr = {}, bool is_sorted = false){
		if(!is_sorted) sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end());;
#define ADDP(C, cmp) while((int)C.size() > 1 && ori(C[(int)C.size() - 2], p, C.back()) cmp 0) C.pop_back(); C.push_back(p);
		for(auto &p: arr){
			if(type < 2){ ADDP(first, >=) }
			if(!(type & 1)){ ADDP(second, <=) }
		}
		reverse(second.begin(), second.end());
	}
	vector<point<T>> get_hull() const{
		if(type) return type == 1 ? first : second;
		if((int)first.size() <= 1) return first;
		vector<point<T>> res(first);
		res.insert(res.end(), ++ second.begin(), -- second.end());
		return res;
	}
	int min_element(const point<T> &p) const{
		assert(p.y >= 0 && !first.empty());
		int low = 0, high = (int)first.size();
		while(high - low >= 3){
			int mid = low + (high - low >> 1);
			p * first[mid - 1] >= p * first[mid] ? low = mid - 1 : high = mid;
		}
		int res = low;
		for(auto i = low + 1; i < high; i ++) if(p * first[res] > p * first[i]) res = i;
		return res;
	}
	int max_element(const point<T> &p) const{
		assert(p.y >= 0 && !second.empty());
		int low = 0, high = (int)second.size();
		while(high - low >= 3){
			int mid = low + (high - low >> 1);
			p * second[mid - 1] <= p * second[mid] ? low = mid - 1 : high = mid;
		}
		int res = low;
		for(auto i = low + 1; i < high; ++ i) if(p * second[res] < p * second[i]) res = i;
		return res;
	}
	vector<point<T>> linearize() const{
		if(type == 1) return first;
		if(type == 2){ vector<point<T>> res(second); reverse(res.begin(), res.end()); return res; }
		if((int)first.size() <= 1) return first;
		vector<point<T>> res;
		res.reserve((int)first.size() + (int)second.size());
		merge(first.begin(), first.end(), ++ second.rbegin(), -- second.rend(), back_inserter(res));
		return res;
	}
	convex_hull operator^(const convex_hull &otr) const{ // Convex Hull Merge
		vector<point<T>> temp, A = linearize(), B = otr.linearize();
		temp.reserve((int)A.size() + (int)B.size());
		merge(A.begin(), A.end(), B.begin(), B.end(), back_inserter(temp));
		return {temp, true};
	}
	pair<vector<point<T>>, vector<point<T>>> get_boundary() const{
		vector<point<T>> L(first), R(second);
		for(auto i = 1; i < (int)first.size(); ++ i) L[i] -= L[0];
		for(auto i = 1; i < (int)second.size(); ++ i) R[i] -= R[0];
		return {L, R};
	}
	convex_hull operator+(const convex_hull &otr) const{ // Minkowski Sum
		assert(type == otr.type);
		compare_by_angle<point<T>> cmp;
		convex_hull res;
		pair<vector<point<T>>, vector<point<T>>> A(this->get_boudnary()), B(otr.get_boudnary());
#define PROCESS(COND, X) \
if(COND && !A.X.empty() && !B.X.empty()){ \
	res.X.reserve((int)A.X.size() + (int)B.X.size()); \
	res.X.push_back(A.X.front() + B.X.front()); \
	merge(A.X.begin() + 1, A.X.end(), B.X.begin() + 1, B.X.end(), back_inserter(res.X)); \
	for(auto i = 1; i < (int)res.X.size(); ++ i) res.X[i] += res.X[i - 1]; \
}
		PROCESS(type < 2, first)
		PROCESS(!(type & 1), second)
		return res;
	}
};

template<class Str>
vector<int> z_function(const Str &s){
	int n = (int)s.size();
	vector<int> z(n);
	for(auto i = 1, j = 0; i < n; ++ i){
		if(i < j + z[j]) z[i] = min(j + z[j] - i, z[i - j]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++ z[i];
		if(i + z[i] > j + z[j]) j = i;
	}
	return z;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<point<long long>> a(n), b(m);
	for(auto &p: a){
		cin >> p;
	}
	for(auto &p: b){
		cin >> p;
	}
	auto C = convex_hull(a).get_hull();
	auto D = convex_hull(b).get_hull();
	if((int)C.size() != (int)D.size()){
		cout << "NO\n";
		return 0;
	}
	debug(C);
	debug(D);
	int sz = (int)C.size();
	C.insert(C.end(), {C[0], C[1]});
	D.insert(D.end(), {D[0], D[1]});
	vector<pair<long long, long long>> c(sz), d(sz);
	for(auto i = 0; i < sz; ++ i){
		c[i] = {(C[i + 1] - C[i]).squared_norm(), (C[i + 1] - C[i]) * (C[i + 2] - C[i + 1])};
		d[i] = {(D[i + 1] - D[i]).squared_norm(), (D[i + 1] - D[i]) * (D[i + 2] - D[i + 1])};
	}
	debug(c);
	debug(d);
	auto combine = [&](auto a, auto b){
		auto res = a;
		res.insert(res.end(), b.begin(), b.end());
		return res;
	};
	auto p = z_function(combine(c, d));
	auto q = z_function(combine(d, c));
	for(auto i = 0; i < sz; ++ i){
		if(p[i + sz] >= sz - i && (!i || q[sz - i + sz] >= i)){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////