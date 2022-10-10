#include <bits/stdc++.h>
using namespace std;

template<class T = long long> struct point{
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

template<class Q, Q (*merge)(Q, Q), Q (*identity)()>
struct segment_tree{
	segment_tree(): segment_tree(0){}
	segment_tree(int n): segment_tree(vector<Q>(n)){}
	segment_tree(const vector<Q> &v): n((int)v.size()){ // O(n)
		log = __lg(n + 1) + 1, size = 1 << log;
		val = vector<Q>(size << 1, identity());
		copy(v.begin(), v.end(), val.begin() + size);
		for(int i = size - 1; i >= 1; -- i) refresh(i);
	}
	void set(int p, Q x){ // O(log n)
		assert(0 <= p && p < n);
		val[p += size] = x;
		for(int i = 1; i <= log; ++ i) refresh(p >> i);
	}
	Q query(int p){ // O(1)
		assert(0 <= p && p < n);
		return val[p + size];
	}
	Q query(int l, int r){ // O(log n)
		assert(0 <= l && l <= r && r <= n);
		Q sml = identity(), smr = identity();
		for(l += size, r += size; l < r; l >>= 1, r >>= 1){
			if(l & 1) sml = merge(sml, val[l ++]);
			if(r & 1) smr = merge(val[-- r], smr);
		}
		return merge(sml, smr);
	}
	Q query_all(){ return val[1]; } // O(1)
	template<class F> int max_pref(int l, F f){ // O(log n)
		assert(0 <= l && l <= n);
		if(l == n) return n;
		l += size;
		Q sm = identity();
		do{
			while(~l & 1) l >>= 1;
			if(!f(merge(sm, val[l]))){
				while(l < size){
					l = l << 1;
					if(f(sm + val[l])) sm = merge(sm, val[l ++]);
				}
				return l - size;
			}
			sm = merge(sm, val[l ++]);
		}while((l & -l) != l);
		return n;
	} // f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	template<class F> int min_suff(int r, F f){ // O(log n)
		assert(0 <= r && r <= n);
		if(r == 0) return 0;
		r += size;
		Q sm = identity();
		do{
			-- r;
			while (r > 1 && r & 1) r >>= 1;
			if(!f(merge(val[r], sm))){
				while(r < size){
					r = r << 1 | 1;
					if(f(merge(val[r], sm))) sm = merge(val[r --], sm);
				}
				return r + 1 - size;
			}
			sm = merge(val[r], sm);
		}while((r & -r) != r);
		return 0;
	} // f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns min l with T
	int n, size, log;
	vector<Q> val;
	void refresh(int i){ val[i] = merge(val[i << 1], val[i << 1 | 1]); }
};
using Q = int; // Monoid (Query Type)
Q merge(Q x, Q y){ // merges adjacent intervals
	return x + y;
}
Q identity(){ // Monoid Identity
	return 0;
}
//	segment_tree<Q, merge, identity> seg(a);

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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	int n;
	long long k;
	cin >> n >> k;
	using P = point<double>;
	vector<P> init(n);
	for(auto &p: init){
		cin >> p.x >> p.y;
	}
	const double eps = 1e-6;
	const double pi = acos(-1);
	auto test = [&](double rad){ // >= k points intersect
		debug(rad);
		vector<P> points;
		for(auto &p: init){
			if(p.norm() > rad){
				points.push_back(p);
			}
		}
		debug(points);
		long long res = 1LL * n * (n - 1) / 2;
		int n = (int)points.size();
		vector<array<double, 2>> range(n);
		vector<double> cmpr;
		vector<tuple<double, double, int>> event;
		for(auto p: points){
			double sz = p.norm();
			double ca = p.x / sz, sa = p.y / sz;
			double ct = sqrt(sz * sz - rad * rad) / sz, st = rad / sz;
			P u{ca * ct - sa * st, ca * st + sa * ct};
			debug(u);
			assert(abs((p - u.normal().normal().normal() * rad) * u.normal().normal().normal() * rad) < eps);
			ca = -ca, sa = -sa;
			st = -st;
			P v{ca * ct - sa * st, ca * st + sa * ct};
			debug(v);
			assert(abs((p - v.normal().normal().normal() * rad) * v.normal().normal().normal() * rad) < eps);
			assert((u ^ v) > 0);
			assert(abs(u.norm() - 1) < eps && abs(v.norm() - 1) < eps);
			double alpha = atan2(u.y, u.x) / (2 * pi), beta = atan2(v.y, v.x) / (2 * pi);
			debug(alpha, beta);
			if(alpha < 0){
				alpha += 1;
			}
			if(beta < 0){
				beta += 1;
			}
			if(beta < alpha){
				beta += 1;
			}
			debug(alpha, beta);
			cmpr.insert(cmpr.end(), {alpha, beta, alpha + 1, beta + 1});
			event.push_back({alpha, beta, 0});
			event.push_back({beta, alpha, 1});
			event.push_back({alpha + 1, beta + 1, 0});
			event.push_back({beta + 1, alpha + 1, 1});
		}
		sort(cmpr.begin(), cmpr.end());
		auto ind = [&](double x){
			return lower_bound(cmpr.begin(), cmpr.end(), x) - cmpr.begin();
		};
		sort(event.begin(), event.end());
		segment_tree<int, merge, identity> seg(4 * n);
		for(auto [t, tt, type]: event){
			if(!type){
				res -= seg.query(ind(t), ind(tt));
				if(t < 1){
					int pos = ind(tt);
					seg.set(pos, seg.query(pos) + 1);
				}
			}
			else{
				if(tt < 1){
					int pos = ind(t);
					seg.set(pos, seg.query(pos) - 1);
				}
			}
		}
		debug(res, "\n");
		return res >= k;
	};
	double low = 0, high = 1e9;
	for(auto rep = 0; rep < 60; ++ rep){
		double mid = (low + high) / 2;
		(test(mid) ? high : low) = mid;
	}
	cout << low << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////