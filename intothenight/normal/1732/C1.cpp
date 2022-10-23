#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

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
		int n, qn;
		cin >> n >> qn;
		vector<int> a(n), next(n + 1, n), prev(n, -1);
		vector<long long> s(n + 1), x(n + 1);
		for(auto i = 0; i < n; ++ i){
			int y;
			cin >> y;
			a[i] = y;
			if(y){
				prev[i] = i;
			}
			else{
				prev[i] = i ? prev[i - 1] : -1;
			}
			s[i + 1] = s[i] + y;
			x[i + 1] = x[i] ^ y;
		}
		auto get = [&](int l, int r)->int{
			debug("query", l, r);
			return s[r] - s[l] - (x[l] ^ x[r]);
		};
		for(auto i = n - 1; i >= 0; -- i){
			next[i] = a[i] ? i : i + 1 < n ? next[i + 1] : n;
		}
		for(auto qi = 0; qi < qn; ++ qi){
			int ql, qr;
			cin >> ql >> qr, -- ql;
			if(next[ql] >= qr){
				cout << ql + 1 << " " << ql + 1 << "\n";
				continue;
			}
			debug(ql, qr, get(ql, qr));
			int l = ql, r = qr;
			for(auto rep = 31; rep >= 0 && r >= 2 && prev[r - 2] >= l && get(l, prev[r - 2] + 1) == get(ql, qr); -- rep){
				r = prev[r - 2] + 1;
			}
			array<int, 2> res{ql, qr};
			while(l < qr){
				while(r <= l || r < qr && get(l, r) != get(ql, qr)){
					debug(r);
					r = next[r] + 1;
				}
				if(r > qr || get(l, r) != get(ql, qr)){
					break;
				}
				debug(l, r);
				if(res[1] - res[0] > r - l){
					res = {l, r};
				}
				l = next[l + 1];
			}
			cout << res[0] + 1 << " " << res[1] << "\n";
		}
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
1100
1000
0011
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////