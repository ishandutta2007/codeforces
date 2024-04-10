#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

// Returns g=gcd(a,b), and x and y store values with ax+by=g
// O(log min(a, b))
template<class T>
T euclid(T a, T b, T &x, T &y){
	if(b){
		T d = euclid(b, a % b, y, x);
		return y -= a / b * x, d;
	}
	return x = 1, y = 0, a;
}

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "{" << p.first << ", " << p.second << "}";
}
template<class Tuple, size_t N> struct _tuple_printer{
	static ostream &_print(ostream &out, const Tuple &t){ return _tuple_printer<Tuple, N-1>::_print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct _tuple_printer<Tuple, 1>{
	static ostream &_print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &_print_tuple(ostream &out, const tuple<Args...> &t){
	return _tuple_printer<decltype(t), sizeof...(Args)>::_print(out << "{", t) << "}";
}
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return _print_tuple(out, t);
}
template<class T> ostream &operator<<(class enable_if<!is_same<T, string>::value, ostream>::type &out, const T &arr){
	if(arr.empty()) return out << "{}";
	out << "{";
	for(auto it = arr.begin(); it != arr.end(); ++ it){
		out << *it;
		next(it) != arr.end() ? out << ", " : out << "}";
	}
	return out;
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(auto i = 0; i < S; ++ i) out << b[i];
	return out;
}
ostream &operator<<(ostream &out, const _Bit_reference &bit){
	return out << bool(bit);
}
template<class T, class A, class C>
ostream &operator<<(ostream &out, priority_queue<T, A, C> pq){
	vector<T> a;
	while(!pq.empty()) a.push_back(pq.top()), pq.pop();
	return out << a;
}
template<class Head>
void debug_out(Head H){ cerr << H << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
enum CODE{ CCRED = 31, CCGREEN = 32, CCYELLOW = 33, CCBLUE = 34, CCDEFAULT = 39 };
#define debug_endl() cerr << endl
#define debug(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m", debug_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m"
#define debug2(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "] \033[" << (int)CODE(CCBLUE) << "m", debug2_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m"
#else
#define debug_endl() 42
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	vector<long long> taste(n + 1);
	for(auto &[x, y]: a){
		cin >> x >> y;
		taste[0] += y;
		x -= y;
	}
	ranges::sort(a | ranges::views::reverse);
	for(auto i = 0; i < n; ++ i){
		taste[i + 1] = taste[i] + a[i][0];
	}
	debug(taste);
	int qn;
	cin >> qn;
	map<array<int, 2>, vector<int>> q;
	vector<long long> res(qn, -1);
	for(auto qi = 0; qi < qn; ++ qi){
		long long x, y, cx, cy;
		cin >> x >> y;
		long long g = euclid(x, y, cx, cy);
		if(n % g){
			continue;
		}
		cx *= n / g, cy *= n / g;
		// n = cx * x + cy * y
		long long l = x / g * y, lx = y / g, ly = x / g;
		if(cx < 0){
			long long d = (-cx + lx - 1) / lx;
			cx += d * lx;
			cy -= d * ly;
		}
		if(cy < 0){
			long long d = (-cy + ly - 1) / ly;
			cy += d * ly;
			cx -= d * lx;
		}
		if(cx < 0 || cy < 0){
			continue;
		}
		int rem = cx * x % l;
		if(l > n){
			res[qi] = taste[rem];
			continue;
		}
		q[{l, rem}].push_back(qi);
	}
	for(auto [state, qis]: q){
		auto [l, rem] = state;
		long long opt = 0;
		for(auto i = rem; i <= n; i += l){
			opt = max(opt, taste[i]);
		}
		for(auto qi: qis){
			res[qi] = opt;
		}
	}
	for(auto x: res){
		cout << x << "\n";
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