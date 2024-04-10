#include <bits/stdc++.h>
using namespace std;

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "{" << p.first << ", " << p.second << "}";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "{", t) << "}";
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
ostream &operator<<(ostream &out, const _Bit_reference &bit){
	return out << bool(bit);
}
template<class T, class A, class C>
ostream &operator<<(ostream &out, priority_queue<T, A, C> pq){
	vector<T> a;
	while(!pq.empty()) a.push_back(pq.top()), pq.pop();
	return out << a;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
void debug_frac_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_frac_out(Head H, Tail... T){
	for(auto d = 1; ; ++ d){
		if((H * d).value <= 1000000){
			cerr << H * d << "/" << d << ", ";
			break;
		}
		else if((-H * d).value <= 1000000){
			cerr << "-" << -H * d << "/" << d << ", ";
			break;
		}
	}
	debug_frac_out(T...);
}
enum CODE{ CCRED = 31, CCGREEN = 32, CCYELLOW = 33, CCBLUE = 34, CCDEFAULT = 39 };
#define debug(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m", debug_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug2(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "] \033[" << (int)CODE(CCBLUE) << "m", debug2_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug_frac(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m", debug_frac_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#else
#define debug(...) 42
#define debug2(...) 42
#define debug_frac(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(1 << n);
	for(auto i = 0; i < 1 << n; ++ i){
		cin >> a[i];
	}
	// <, >
	vector<array<long long, 2>> val(1 << n + 1);
	vector<array<long long, 2>> seg(1 << n + 1);
	vector<int> left(1 << n + 1, -1);
	vector<int> right(1 << n + 1, -1);
	auto refresh = [&](int u)->void{
		for(auto t = 0; t < 2; ++ t){
			seg[u][t] = val[u][t] + seg[left[u]][t] + seg[right[u]][t];
		}
	};
	y_combinator([&](auto self, int u, int l, int r)->void{
		if(r - l == 1){
			return;
		}
		int m = l + r >> 1, v = u << 1, w = u << 1 | 1;
		left[u] = v, right[u] = w;
		self(v, l, m), self(w, m, r);
		for(auto t = 0; t < 2; ++ t){
			seg[u][t] = seg[v][t] + seg[w][t];
		}
		vector<int> temp(a.begin() + l, a.begin() + m);
		sort(temp.begin(), temp.end());
		for(auto i = m; i < r; ++ i){
			auto [p, q] = equal_range(temp.begin(), temp.end(), a[i]);
			val[u][0] += p - temp.begin();
			val[u][1] += temp.end() - q;
		}
		refresh(u);
	})(1, 0, 1 << n);
	debug(val);
	debug(seg);
	debug(left);
	debug(right);
	debug("\n");
	auto flip = [&](int ql, int qr)->void{
		if(qr - ql == 1){
			return;
		}
		y_combinator([&](auto self, int u, int l, int r)->void{
			if(r <= ql || qr <= l){
				return;
			}
			if(ql <= l && r <= qr){
				swap(left[u], right[u]);
				swap(val[u][0], val[u][1]);
				refresh(u);
				return;
			}
			int m = l + r >> 1;
			self(left[u], l, m), self(right[u], m, r);
			refresh(u);
		})(1, 0, 1 << n);
	};
	int qn;
	cin >> qn;
	vector<vector<int>> q(1 << n);
	for(auto qi = 0; qi < qn; ++ qi){
		int x;
		static int last = 0;
		cin >> x, last = x = (1 << x) - 1 ^ last;
		q[x].push_back(qi);
	}
	debug2(q);
	debug("\n");
	vector<long long> res(qn, -1);
	for(auto qi: q[0]){
		res[qi] = seg[1][1];
	}
	for(auto t = 1; t < 1 << n; ++ t){
		int x = t - 1 ^ t - 1 >> 1 ^ t ^ t >> 1;
		assert(__builtin_popcount(x) == 1);
		x = n - 1 - __lg(x);
		debug(t, x);
		for(auto l = 0, r = 1 << x + 1; r <= 1 << n; l += 1 << x + 1, r += 1 << x + 1){
			debug(l, r);
			flip(l, r);
		}
		debug(val);
		debug(seg);
		debug(left);
		debug(right);
		debug("\n");
		static int last = 0;
		last ^= 1 << x;
		for(auto qi: q[last]){
			res[qi] = seg[1][1];
		}
	}
	for(auto x: res){
		assert(~x);
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