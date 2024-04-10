#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class L, class R> istream &operator>>(istream &in, pair<L, R> &p){ return in >> p.first >> p.second; }
template<class Tuple, size_t ...Is> void read_tuple(istream &in, Tuple &t, index_sequence<Is...>){ ((in >> get<Is>(t)), ...); }
template<class ...Args> istream &operator>>(istream &in, tuple<Args...> &t){ read_tuple(in, t, index_sequence_for<Args...>{}); return in; }
template<class ...Args, template<class...> class T> istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){ for(auto &x: arr) in >> x; return in; }
//template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << "(" << p.first << ", " << p.second << ")"; }
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << p.first << " " << p.second << "\n"; }
template<class Tuple, size_t ...Is> void print_tuple(ostream &out, const Tuple &t, index_sequence<Is...>){ ((out << (Is ? " " : "") << get<Is>(t)), ...); }
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){ print_tuple(out, t, index_sequence_for<Args...>{}); return out << "\n"; }
template<class ...Args, template<class...> class T> ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){ for(auto &x: arr) out << x << " "; return out << "\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<class T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;

template<class T = ll> struct point{
	T x, y;
	int from, to;
	template<class U> point(const point<U> &otr): x(otr.x), y(otr.y){ }
	template<class U, class V> point(const pair<U, V> &p): x(p.first), y(p.second){ }
	template<class U = T, class V = T> point(U x = 0, V y = 0): x(x), y(y){ }
	template<class U> explicit operator point<U>() const{ return point<U>(static_cast<U>(x), static_cast<U>(y)); }
	T operator*(const point &otr) const{ return x * otr.x + y * otr.y; }
	T operator^(const point &otr) const{ return x * otr.y - y * otr.x; }
	point operator+(const point &otr) const{ return point(x + otr.x, y + otr.y); }
	point &operator+=(const point &otr){ return *this = *this + otr; }
	point operator-(const point &otr) const{ return point(x - otr.x, y - otr.y); }
	point &operator-=(const point &otr){ return *this = *this - otr; }
	point operator*(const T &c) const{ return point(x * c, y * c); }
	point &operator*=(const T &c) { return *this = *this * c; }
	point operator/(const T &c) const{ return point(x / c, y / c); }
	point &operator/=(const T &c) { return *this = *this / c; }
	point operator-() const{ return point(-x, -y); }
	bool operator<(const point &otr) const{ return tie(x, y) < tie(otr.x, otr.y); }
	bool operator>(const point &otr) const{ return tie(x, y) > tie(otr.x, otr.y); }
	bool operator<=(const point &otr) const{ return tie(x, y) <= tie(otr.x, otr.y); }
	bool operator>=(const point &otr) const{ return tie(x, y) >= tie(otr.x, otr.y); }
	bool operator==(const point &otr) const{ return tie(x, y) == tie(otr.x, otr.y); }
	bool operator!=(const point &otr) const{ return tie(x, y) != tie(otr.x, otr.y); }
	double norm() const{ return sqrt(x * x + y * y); }
	T sqnorm() const{ return x * x + y * y; }
	double arg() const{ return atan2(y, x); } // [-pi, pi]
	point<double> unit() const{ return point<double>(x, y) / norm(); }
	point perp() const{ return point(-y, x); }
	point<double> normal() const{ return perp().unit(); }
	point<double> rotate(const double &theta) const{ return point<double>(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)); }
	point reflect_x() const{ return point(x, -y); }
	point reflect_y() const{ return point(-x, y); }
};
template<class T> point<T> operator*(const T &c, const point<T> &p){ return point<T>(c * p.x, c * p.y); }
template<class T> istream &operator>>(istream &in, point<T> &p){ return in >> p.x >> p.y; }
template<class T> ostream &operator<<(ostream &out, const point<T> &p){ return out << pair<T, T>(p.x, p.y); }
template<class T> double distance(const point<T> &p, const point<T> &q){ return (p - q).norm(); }
template<class T> T squared_distance(const point<T> &p, const point<T> &q){ return (p - q).sqnorm(); }
template<class T, class U, class V> T ori(const point<T> &p, const point<U> &q, const point<V> &r){ return (q - p) ^ (r - p); }
template<class T> T doubled_signed_area(const vector<point<T>> &arr){
	T s = arr.back() ^ arr.front();
	for(int i = 1; i < sz(arr); ++ i) s += arr[i - 1] ^ arr[i];
	return s;
}
template<class T = ll> struct line{
	point<T> p, d; // p + d*t
	template<class U = T, class V = T> line(point<U> p = {0, 0}, point<V> q = {0, 0}, bool Two_Points = true): p(p), d(Two_Points ? q - p : q){ }
	template<class U> line(point<U> d): p(), d(static_cast<point<T>>(d)){ }
	line(T a, T b, T c): p(a ? -c / a : 0, !a && b ? -c / b : 0), d(-b, a){ }
	template<class U> explicit operator line<U>() const{ return line<U>(point<U>(p), point<U>(d), false); }
	point<T> q() const{ return p + d; }
	bool degen() const{ return d == point<T>(); }
	tuple<T, T, T> coef(){ return {d.y, -d.x, d.perp() * p}; } // d.y (X - p.x) - d.x (Y - p.y) = 0
};
template<class T> bool parallel(const line<T> &L, const line<T> &M){ return !(L.d ^ M.d); }
template<class T> bool on_line(const point<T> &p, const line<T> &L){
	if(L.degen()) return p == L.p;
	return (p - L.p) ^ L.d == 0;
}
template<class T> bool on_ray(const point<T> &p, const line<T> &L){
	if(L.degen()) return p == L.p;
	auto a = L.p - p, b = L.q() - p;
	return !(a ^ b) && a * L.d <= 0;
}
template<class T> bool on_segment(const point<T> &p, const line<T> &L){
	if(L.degen()) return p == L.p;
	auto a = L.p - p, b = L.q() - p;
	return !(a ^ b) && a * b <= 0;
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
template<class T> pair<bool, point<double>> intersect_closed_segments_no_parallel_overlap(const line<T> &L, const line<T> &M) {
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
	if(parallel(L, M)){
		if(L.d * M.d >= 0 || (M.p - L.p) * M.d <= 0) return distance_to_line(L.p, M);
		else return distance(L.p, M.p);
	}
	else{
		if(intersect_no_parallel_overlap<1, 0, 1, 0, ll>(L, M).first) return 0;
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
template<class It, class P> void sort_by_angle(It first, It last, const P &origin){
	first = partition(first, last, [&origin](const decltype(*first) &point){ return point == origin; });
	auto pivot = partition(first, last, [&origin](const decltype(*first) &point) { return point > origin; });
	compare_by_angle<P> cmp(origin);
	sort(first, pivot, cmp), sort(pivot, last, cmp);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	ll S;
	cin >> n >> S, S <<= 1;
	vector<point<ll>> a(n);
	for(auto &x: a){
		static int i = 0;
		cin >> x;
		x.from = i ++;
	}
	vector<point<ll>> t;
	t.reserve(n * n);
	for(int i = 0; i < n; ++ i){
		for(int j = i + 1; j < n; ++ j){
			t.push_back(a[i] - a[j]);
			t.back().from = j, t.back().to = i;
			t.push_back(a[j] - a[i]);
			t.back().from = i, t.back().to = j;
		}
	}
	sort_by_angle(all(t), point<ll>{0, 0});
	sort(all(a));
	vi pos(n);
	for(int i = 0; i < n; ++ i){
		pos[a[i].from] = i;
	}
	auto kill = [](tuple<point<ll>, point<ll>, point<ll>> x){
	    cout << "Yes\n" << x;
	    exit(0);
	};
	for(auto p: t){
		int i = lower_bound(all(a), point<ll>(), [&](const point<ll> &q, const point<ll> &r){
			return ori(a[pos[p.from]], a[pos[p.to]], q) < S;
		}) - a.begin();
		if(i < n && S == ori(a[pos[p.from]], a[pos[p.to]], a[i])){
			kill({a[pos[p.from]], a[pos[p.to]], a[i]});
		}
		if(p.x || p.y > 0){
			swap(a[pos[p.from]], a[pos[p.to]]);
			swap(pos[p.from], pos[p.to]);
		}
	}
	cout << "No";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////