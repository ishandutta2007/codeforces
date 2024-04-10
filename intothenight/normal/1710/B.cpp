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
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, th;
		cin >> n >> th;
		vector<array<int, 2>> a(n);
		vector<pair<long long, int>> update;
		vector<int> b;
		for(auto &[x, p]: a){
			cin >> x >> p;
			b.push_back(x);
			update.push_back({x - p, 1});
			update.push_back({x, -2});
			update.push_back({x + p, 1});
		}
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		int m = (int)b.size();
		vector<long long> amount(m, -1);
		{
			sort(update.begin(), update.end());
			debug(update);
			int lastpos = numeric_limits<int>::min();
			long long value = 0, delta = 0;
			int j = 0;
			for(auto i = 0; i < m; ++ i){
				while(j < (int)update.size() && update[j].first <= b[i]){
					auto [x, d] = update[j ++];
					value += 1LL * (x - lastpos) * delta;
					delta += d;
					lastpos = x;
					debug(j, lastpos, value, delta);
				}
				amount[i] = value + (b[i] - lastpos) * delta;
			}
		}
		debug(b);
		debug(amount);
		array<long long, 2> req{numeric_limits<long long>::min(), numeric_limits<long long>::min()};
		for(auto i = 0; i < m; ++ i){
			if(amount[i] > th){
				int x = b[i];
				long long r = amount[i] - th;
				ctmax(req[0], r - x);
				ctmax(req[1], r + x);
			}
		}
		for(auto [x, p]: a){
			cout << (p - x >= req[0] && p + x >= req[1]);
		}
		cout << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
	}
	return 0;
}

/*


0 0 0 0 1 2 .. p-1 p p-1 ...  2  1 0 0
0 0 0 0 1 1 .. 1   1 -1  ... -1 -1 -1 0
0 0 0 0 1 0 .. 0   0 -1  ... 0   0  0 1
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////