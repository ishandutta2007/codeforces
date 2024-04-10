#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct point3{
	T x{}, y{}, z{};
	point3(){ }
	template<class U> point3(const point3<U> &otr): x(otr.x), y(otr.y), z(otr.z){ }
	template<class U, class V, class W> point3(U x, V y, W z): x(x), y(y), z(z){ }
	template<class U> point3(const array<U, 3> &p): x(p[0]), y(p[1]), z(p[2]){ }
	template<class U> operator array<U, 3>() const{
		return {x, y, z};
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
	double norml() const{
		return sqrtl(x * x + y * y + z * z);
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
long double distancel(const point3<T> &p, const point3<T> &q){
	return (p - q).norml();
}
template<class T>
T squared_distance(const point3<T> &p, const point3<T> &q){
	return (p - q).squared_norm();
}
template<class T>
double angle(const point3<T> &p, const point3<T> &q){
	return atan2((p ^ q).norm(), p * q);
}
template<class T>
long double anglel(const point3<T> &p, const point3<T> &q){
	return atan2l((p ^ q).norml(), p * q);
}

using point3int = point3<int>;
using point3ll = point3<long long>;
using point3lll = point3<__int128_t>;
using point3d = point3<double>;
using point3ld = point3<long double>;

template<bool Enable_small_to_large = true>
struct disjoint_set{
	int n, _classes;
	vector<int> p;
	disjoint_set(int n): n(n), _classes(n), p(n, -1){ }
	int classes() const{
		return _classes;
	}
	int root(int u){
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
	bool share(int a, int b){
		return root(a) == root(b);
	}
	int size(int u){
		return -p[root(u)];
	}
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		if constexpr(Enable_small_to_large) if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
	bool merge(int u, int v, auto act){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		if constexpr(Enable_small_to_large) if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		act(u, v);
		return true;
	}
	void clear(){
		_classes = n;
		fill(p.begin(), p.end(), -1);
	}
	vector<vector<int>> group_up(){
		vector<vector<int>> g(n);
		for(auto i = 0; i < n; ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	int n;
	cin >> n;
	vector<point3ll> a(n);
	copy_n(istream_iterator<point3ll>(cin), n, a.begin());
	vector<array<long double, 3>> delta(n);
	vector<vector<int>> connect(n);
	int m;
	cin >> m;
	for(auto rep = m; rep; -- rep){
		array<int, 3> id;
		for(auto i = 0; i < 3; ++ i){
			cin >> id[i], -- id[i];
		}
		ranges::sort(id, [&](int i, int j){ return a[i].z > a[j].z; });
		for(auto i = 0; i < 3; ++ i){
			for(auto j = 0; j < i; ++ j){
				connect[id[i]].push_back(id[j]);
			}
		}
		point3ld p = a[id[0]];
		point3ld q1 = a[id[1]];
		point3ld r = a[id[2]];
		if(a[id[0]].z == a[id[2]].z){
			delta[id[2]][0] += (p - q1 ^ p - r).norml() / 2;
			continue;
		}
		long double x = p.z - q1.z;
		long double y = q1.z - r.z;
		point3ld q2 = (p * y + r * x) / (x + y);
		long double m = distance(q1, q2);
		long double upper = (p - q1 ^ p - q2).norml() / 2;
		long double lower = (r - q1 ^ r - q2).norml() / 2;
		if(a[id[0]].z > a[id[1]].z){
			delta[id[0]][0] += upper * p.z * p.z / x / x;
			delta[id[0]][1] += -2 * upper * p.z / x / x;
			delta[id[0]][2] += upper / x / x;
			delta[id[1]][0] += upper - upper * p.z * p.z / x / x;
			delta[id[1]][1] += 2 * upper * p.z / x / x;
			delta[id[1]][2] += -1 * upper / x / x;
		}
		if(a[id[1]].z > a[id[2]].z){
			delta[id[1]][0] += lower * (1 - r.z * r.z / y / y);
			delta[id[1]][1] += 2 * lower * r.z / y / y;
			delta[id[1]][2] += -1 * lower / y / y;
			delta[id[2]][0] += lower * r.z * r.z / y / y;
			delta[id[2]][1] += -2 * lower * r.z / y / y;
			delta[id[2]][2] += lower / y / y;
		}
	}
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	ranges::sort(order, [&](int i, int j){ return a[i].z < a[j].z; });
	int qn;
	cin >> qn;
	vector<array<int, 3>> query(qn);
	for(auto qi = 0; qi < qn; ++ qi){
		int h, i;
		cin >> h >> i, -- i;
		query[qi] = {h, i, qi};
	}
	ranges::sort(query | ranges::views::reverse);
	vector<long double> res(qn);
	vector<array<long double, 3>> f(n);
	disjoint_set dsu(n);
	for(auto [h, i, qi]: query){
		while(!order.empty() && a[order.back()].z > h){
			int i = order.back();
			order.pop_back();
			for(auto j: connect[i]){
				dsu.merge(i, j, [&](int i, int j){
					f[i][0] += f[j][0];
					f[i][1] += f[j][1];
					f[i][2] += f[j][2];
				});
			}
			f[dsu.root(i)][0] += delta[i][0];
			f[dsu.root(i)][1] += delta[i][1];
			f[dsu.root(i)][2] += delta[i][2];
		}
		if(a[i].z <= h){
			res[qi] = -1;
			continue;
		}
		i = dsu.root(i);
		res[qi] =  f[i][0] + f[i][1] * h + f[i][2] * h * h;
	}
	ranges::copy(res, ostream_iterator<long double>(cout, "\n"));
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////