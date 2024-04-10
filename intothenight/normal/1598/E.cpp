#include <bits/stdc++.h>
using namespace std;

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
	int n, m, qn;
	cin >> n >> m >> qn;
	vector<vector<int>> state(n, vector<int>(m));
	vector<set<int>> notfree(n + m + 10);
	int delta = m + 5;
	for(auto i = -2; i <= n + 2; ++ i){
		for(auto j = -2; j <= m + 2; ++ j){
			notfree[i - j + delta].insert(i);
		}
	}
	debug2(notfree);
	long long res = 0;
	auto calc = [&](int i, int j)->long long{
		debug("calculating", i, j);
		debug("center", i - j + delta);
		debug2(state);
		debug(notfree[i - j + 1 + delta]);
		debug(notfree[i - j + delta]);
		debug(notfree[i - j - 1 + delta]);
		// assumes i, j is free
		long long res = -1;
		auto temp = notfree[i - j + delta].lower_bound(i);
		int x = *temp - i;
		int rx = i - *prev(temp);
		debug(x, rx);
		{ // upper
			auto it = notfree[i - j - 1 + delta].lower_bound(i);
			debug(*prev(it), *it);
			int y = *it - i;
			int p = x <= y ? 2 * x : 2 * y + 1;
			int ry = i - 1 - *prev(it);
			int q = rx <= ry ? 2 * rx : 2 * ry + 1;
			debug(y, ry, p, q);
			res += 1LL * p * q;
		}
		{ // lower
			auto it = notfree[i - j + 1 + delta].lower_bound(i + 1);
			debug(*prev(it), *it);
			int y = *it - i - 1;
			int p = x <= y ? 2 * x : 2 * y + 1;
			int ry = i - *prev(it);
			int q = rx <= ry ? 2 * rx : 2 * ry + 1;
			debug(y, ry, p, q);
			res += 1LL * p * q;
		}
		debug(res, "\n");
		return res;
	};
	auto flip = [&](int i, int j)->void{
		if(state[i][j]){
			res -= calc(i, j);
			state[i][j] ^= 1;
			notfree[i - j + delta].insert(i);
		}
		else{
			state[i][j] ^= 1;
			notfree[i - j + delta].erase(i);
			res += calc(i, j);
		}
	};
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			flip(i, j);
		}
	}
	debug(res);
	for(auto qi = 0; qi < qn; ++ qi){
		int i, j;
		cin >> i >> j, -- i, -- j;
		flip(i, j);
		cout << res << "\n";
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