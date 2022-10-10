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

template<typename T>
struct counting_iterator: public iterator<random_access_iterator_tag, bool>{
	T value = 0;
	counting_iterator(const T &value): value(value){}
	counting_iterator(const counting_iterator &it): value(it.value){}
	counting_iterator(){}
	typename iterator_traits<counting_iterator>::difference_type operator-(const counting_iterator &it) const{ return value - it.value; }
	counting_iterator &operator++(){ return *this += 1; }
	counting_iterator &operator--(){ return *this += -1; }
	counting_iterator &operator+=(typename iterator_traits<counting_iterator>::difference_type n){ value += n; return *this; }
	bool operator!=(const counting_iterator &it) const{ return value != it.value; }
	T &operator*(){ return value; }
};
using iterint = counting_iterator<int>;
using iterll = counting_iterator<long long>;

// Returns g=gcd(a,b), and x and y store values with ax+by=g
using ll = long long;
ll euclid(ll a, ll b, ll &x, ll &y){
	if(b){
		ll d = euclid(b, a % b, y, x);
		return y -= a / b * x, d;
	}
	return x = 1, y = 0, a;
}

// Requires euclid
// solutions to ax + by = c where x in [xlow, xhigh] and y in [ylow, yhigh]
// cnt, leftsol, rightsol, gcd of a and b
array<ll, 6> solve_linear_diophantine(ll a, ll b, ll c, ll xlow, ll xhigh, ll ylow, ll yhigh){
	ll x, y, g = euclid(a >= 0 ? a : -a, b >= 0 ? b : -b, x, y);
	array<ll, 6> no_sol{0, 0, 0, 0, 0, g};
	if(c % g) return no_sol;
	x *= c / g, y *= c / g;
	if(a < 0) x = -x;
	if(b < 0) y = -y;
	a /= g, b /= g, c /= g;
	auto shift = [&](ll &x, ll &y, ll a, ll b, ll cnt){ x += cnt * b, y -= cnt * a; };
	int sign_a = a > 0 ? 1 : -1, sign_b = b > 0 ? 1 : -1;

	shift(x, y, a, b, (xlow - x) / b);
	if(x < xlow) shift(x, y, a, b, sign_b);
	if(x > xhigh) return no_sol;
	ll lx1 = x;
	
	shift(x, y, a, b, (xhigh - x) / b);
	if(x > xhigh) shift(x, y, a, b, -sign_b);
	ll rx1 = x;

	shift(x, y, a, b, -(ylow - y) / a);
	if(y < ylow) shift(x, y, a, b, -sign_a);
	if(y > yhigh) return no_sol;
	ll lx2 = x;

	shift(x, y, a, b, -(yhigh - y) / a);
	if(y > yhigh) shift(x, y, a, b, sign_a);
	ll rx2 = x;

	if(lx2 > rx2) swap(lx2, rx2);
	ll lx = max(lx1, lx2), rx = min(rx1, rx2);
	if(lx > rx) return no_sol;
	return {(rx - lx) / (b >= 0 ? b : -b) + 1, lx, (c - lx * a) / b, rx, (c - rx * a) / b, g};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	long long l, k;
	cin >> n >> m >> k, l = lcm<long long>(n, m);
	vector<int> posa(2 * max(n, m), -1);
	vector<int> posb(2 * max(n, m), -1);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x, -- x;
		posa[x] = i;
	}
	for(auto i = 0; i < m; ++ i){
		int x;
		cin >> x, -- x;
		posb[x] = i;
	}
	long long common = l;
	vector<long long> sol(2 * max(n, m), -1);
	for(auto x = 0; x < 2 * max(n, m); ++ x){
		if(~posa[x] && ~posb[x]){
			auto [cnt, c, d, tt, ttt, tttt] = solve_linear_diophantine(n, -m, posb[x] - posa[x], 0, m - 1, 0, n - 1);
			debug(x, posa[x], posb[x]);
			debug(cnt, c, d, tt, ttt, tttt);
			if(cnt){
				-- common;
				assert(posa[x] + n * c == posb[x] + m * d);
				sol[x] = posa[x] + n * c;
			}
		}
	}
	debug(common);
	debug(sol);
	auto ok = [&](long long days){
		debug(days);
		if(__builtin_mul_overflow_p(common, days / l, 0LL)){
			return false;
		}
		long long cur = 1LL * common * (days / l);
		days %= l;
		cur += days;
		for(auto x = 0; x < 2 * max(n, m); ++ x){
			if(~sol[x] && sol[x] < days){
				-- cur;
			}
		}
		debug(cur);
		return cur < k;
	};
	cout << *partition_point(iterll(1), iterll(numeric_limits<long long>::max()), ok) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////