#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T = long long> struct point{
	T x, y;
	int ind;
	template<typename U> point(const point<U> &otr): x(otr.x), y(otr.y), ind(otr.ind){ }
	template<typename U, typename V> point(const pair<U, V> &p): x(p.first), y(p.second){ }
	template<typename U = T, typename V = T> point(U x = 0, V y = 0): x(x), y(y){ }
	template<typename U> explicit operator point<U>() const{ return point<U>(static_cast<U>(x), static_cast<U>(y)); }
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
	T squared_norm() const{ return x * x + y * y; }
	double arg() const{ return atan2(y, x); } // [-pi, pi]
	point<double> unit() const{ return point<double>(x, y) / norm(); }
	point perp() const{ return point(-y, x); }
	point<double> normal() const{ return perp().unit(); }
	point<double> rotate(const double &theta) const{ return point<double>(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)); }
	point reflect_x() const{ return point(x, -y); }
	point reflect_y() const{ return point(-x, y); }
	bool operator||(const point &otr) const{ return !(*this ^ otr); }
};
template<typename T> point<T> operator*(const T &c, const point<T> &p){ return point<T>(c * p.x, c * p.y); }
template<typename T> istream &operator>>(istream &in, point<T> &p){ return in >> p.x >> p.y; }
template<typename T> ostream &operator<<(ostream &out, const point<T> &p){ return out << "(" << p.x << ", " << p.y << ")"; }
template<typename T> double distance(const point<T> &p, const point<T> &q){ return (p - q).norm(); }
template<typename T> T squared_distance(const point<T> &p, const point<T> &q){ return (p - q).squared_norm(); }
template<typename T, typename U, typename V> T ori(const point<T> &p, const point<U> &q, const point<V> &r){ return (q - p) ^ (r - p); }
template<typename T> T doubled_signed_area(const vector<point<T>> &arr){
	T s = arr.back() ^ arr.front();
	for(int i = 1; i < arr.size(); ++ i) s += arr[i - 1] ^ arr[i];
	return s;
}
template<typename T = long long> struct line{
	point<T> p, d; // p + d*t
	template<typename U = T, typename V = T> line(point<U> p = {0, 0}, point<V> q = {0, 0}, bool Two_Points = true): p(p), d(Two_Points ? q - p : q){ }
	template<typename U> line(point<U> d): p(), d(static_cast<point<T>>(d)){ }
	line(T a, T b, T c): p(a ? -c / a : 0, !a && b ? -c / b : 0), d(-b, a){ }
	template<typename U> explicit operator line<U>() const{ return line<U>(point<U>(p), point<U>(d), false); }
	point<T> q() const{ return p + d; }
	bool degen() const{ return d == point<T>(); }
	tuple<T, T, T> coef(){ return {d.y, -d.x, d.perp() * p}; } // d.y (X - p.x) - d.x (Y - p.y) = 0
	bool operator||(const line<T> &L){ return d || L.d; }
};
template<typename T> bool on_line(const point<T> &p, const line<T> &L){
	if(L.degen()) return p == L.p;
	return (p - L.p) || L.d;
}
template<typename T> bool on_ray(const point<T> &p, const line<T> &L){
	if(L.degen()) return p == L.p;
	auto a = L.p - p, b = L.q() - p;
	return (a || b) && a * L.d <= 0;
}
template<typename T> bool on_segment(const point<T> &p, const line<T> &L){
	if(L.degen()) return p == L.p;
	auto a = L.p - p, b = L.q() - p;
	return (a || b) && a * b <= 0;
}
template<typename T> double distance_to_line(const point<T> &p, const line<T> &L){
	if(L.degen()) return distance(p, L.p);
	return abs((p - L.p) ^ L.d) / L.d.norm();
}
template<typename T> double distance_to_ray(const point<T> &p, const line<T> &L){
	if((p - L.p) * L.d <= 0) return distance(p, L.p);
	return distance_to_line(p, L);
}
template<typename T> double distance_to_segment(const point<T> &p, const line<T> &L){
	if((p - L.p) * L.d <= 0) return distance(p, L.p);
	if((p - L.q()) * L.d >= 0) return distance(p, L.q());
	return distance_to_line(p, L);
}
template<typename T> point<double> projection(const point<T> &p, const line<T> &L){ return static_cast<point<double>>(L.p) + (L.degen() ? point<double>() : (p - L.p) * L.d / L.d.norm() * static_cast<point<double>>(L.d)); }
template<typename T> point<double> reflection(const point<T> &p, const line<T> &L){ return 2.0 * projection(p, L) - static_cast<point<double>>(p); }
template<typename T> point<double> closest_point_on_segment(const point<T> &p, const line<T> &L){ return (p - L.p) * L.d <= 0 ? static_cast<point<double>>(L.p) : ((p - L.q()) * L.d >= 0 ? static_cast<point<double>>(L.q()) : projection(p, L)); }
template<int TYPE> struct EndpointChecker{ };
// For rays
template<> struct EndpointChecker<0>{ template<typename T> bool operator()(const T& a, const T& b) const{ return true; } }; // For ray
// For closed end
template<> struct EndpointChecker<1>{ template<typename T> bool operator()(const T& a, const T& b) const{ return a <= b; } }; // For closed end
// For open end
template<> struct EndpointChecker<2>{ template<typename T> bool operator()(const T& a, const T& b) const{ return a < b; } }; // For open end
// Assumes parallel lines do not intersect
template<int LA, int LB, int RA, int RB, typename T> pair<bool, point<double>> intersect_no_parallel_overlap(const line<T> &L, const line<T> &M){
	auto s = L.d ^ M.d;
	if(!s) return {false, point<double>()};
	auto ls = (M.p - L.p) ^ M.d, rs = (M.p - L.p) ^ L.d;
	if(s < 0) s = -s, ls = -ls, rs = -rs;
	bool intersect = EndpointChecker<LA>()(decltype(ls)(0), ls) && EndpointChecker<LB>()(ls, s) && EndpointChecker<RA>()(decltype(rs)(0), rs) && EndpointChecker<RB>()(rs, s);
	return {intersect, static_cast<point<double>>(L.p) + 1.0 * ls / s * static_cast<point<double>>(L.d)};
}
// Assumes parallel lines do not intersect
template<typename T> pair<bool, point<double>> intersect_closed_segments_no_parallel_overlap(const line<T> &L, const line<T> &M){
	return intersect_no_parallel_overlap<1, 1, 1, 1>(L, M);
}
// Assumes nothing
template<typename T> pair<bool, line<double>> intersect_closed_segments(const line<T> &L, const line<T> &M){
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
template<typename T> double distance_between_rays(const line<T> &L, const line<T> &M){
	if(L || M){
		if(L.d * M.d >= 0 || (M.p - L.p) * M.d <= 0) return distance_to_line(L.p, M);
		else return distance(L.p, M.p);
	}
	else{
		if(intersect_no_parallel_overlap<1, 0, 1, 0, long long>(L, M).first) return 0;
		else return min(distance_to_ray(L.p, M), distance_to_ray(M.p, L));
	}
}
template<typename T> double distance_between_segments(const line<T> &L, const line<T> &M){
	if(intersect_closed_segments(L, M).first) return 0;
	return min({distance_to_segment(L.p, M), distance_to_segment(L.q(), M), distance_to_segment(M.p, L), distance_to_segment(M.q(), L)});
}
template<typename P> struct compare_by_angle{
	const P origin;
	compare_by_angle(const P &origin = P()): origin(origin){ }
	bool operator()(const P &p, const P &q) const{ return ori(origin, p, q) > 0; }
};
template<typename It, typename P> void sort_by_angle(It first, It last, const P &origin){
	first = partition(first, last, [&origin](const decltype(*first) &point){ return point == origin; });
	auto pivot = partition(first, last, [&origin](const decltype(*first) &point) { return point > origin; });
	compare_by_angle<P> cmp(origin);
	sort(first, pivot, cmp), sort(pivot, last, cmp);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int k, n;
	cin >> k >> n;
	typedef point<long long> P;
	typedef line<long long> L;
	vector<P> a(k), b(n);
	for(auto i = 0; i < k; ++ i){
		cin >> a[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> b[i];
	}
	vector<vector<vector<int>>> blocked(k, vector<vector<int>>(n));
	for(auto i = 0; i < k; ++ i){
		for(auto j = 0; j < n; ++ j){
			L l(a[i], b[j]);
			for(auto jj = 0; jj < n; ++ jj){
				if(j != jj && on_segment(b[jj], l)){
					blocked[i][j].push_back(jj);
					if(int(blocked[i][j].size()) == k){
						break;
					}
				}
			}
			sort(blocked[i][j].begin(), blocked[i][j].end(), [&](int j1, int j2){ return squared_distance(a[i], b[j1]) < squared_distance(a[i], b[j2]); });
		}
	}
	vector<int> perm(k), restore, used(n);
	int res = 0;
	for(auto j = 0; j < n; ++ j){
		bool ded = false;
		iota(perm.begin(), perm.end(), 0);
		do{
			static int IT = 0;
			++ IT;
			int i = 0;
			function<bool(int)> test = [&](int v){
				if(i == k){
					return false;
				}
				int u = perm[i ++];
				used[v] = IT;
				for(auto t: blocked[u][v]){
					if(used[t] != IT && !test(t)){
						return false;
					}
				}
				return true;
			};
			if(test(j)){
				ded = true;
				break;
			}
		}while(next_permutation(perm.begin(), perm.end()));
		res += ded;
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