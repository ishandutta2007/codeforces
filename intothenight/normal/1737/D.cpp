#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct floyd_warshall{
	int n;
	vector<vector<T>> dist;
	floyd_warshall(int n): n(n), dist(n, vector<T>(n)){ }
	// Assumes the graph has no negative cycle
	// O(|V|^3)
	template<class U>
	void run(const vector<vector<U>> &adjm){
		assert(!n && adjm.empty() || n == (int)adjm.size() && n == (int)adjm[0].size());
		for(auto u = 0; u < n; ++ u) for(auto v = 0; v < n; ++ v) dist[u][v] = adjm[u][v];
		for(auto w = 0; w < n; ++ w) for(auto u = 0; u < n; ++ u) for(auto v = 0; v < n; ++ v) dist[u][v] = min(dist[u][v], dist[u][w] + dist[w][v]);
	}
	template<class U>
	void run(const vector<tuple<int, int, U>> &edge, bool directed = false){
		vector<vector<T>> adjm(n, vector<T>(n, numeric_limits<T>::max() / 2));
		for(auto u = 0; u < n; ++ u) adjm[u][u] = 0;
		for(auto [u, v, w]: edge){
			adjm[u][v] = min<T>(adjm[u][v], w);
			if(!directed) adjm[v][u] = adjm[u][v];
		}
		run(adjm);
	}
	// Requires graph
	template<class G>
	void run(const G &g, bool directed = false){
		vector<vector<T>> adjm(n, vector<T>(n, numeric_limits<T>::max() / 2));
		for(auto u = 0; u < n; ++ u) adjm[u][u] = 0;
		for(auto [u, v, w]: g.edge){
			adjm[u][v] = min<T>(adjm[u][v], w);
			if(!directed) adjm[v][u] = adjm[u][v];
		}
		run(adjm);
	}
};

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
		int n, m;
		cin >> n >> m;
		vector<array<int, 3>> edge(m);
		vector<vector<int>> adjm(n, vector<int>(n, numeric_limits<int>::max() / 2));
		for(auto &[u, v, w]: edge){
			cin >> u >> v >> w, -- u, -- v;
			adjm[u][v] = adjm[v][u] = 1;
		}
		floyd_warshall<int> fw(n);
		for(auto u = 0; u < n; ++ u){
			adjm[u][u] = 0;
		}
		fw.run(adjm);
		debug2(fw.dist);
		long long res = numeric_limits<long long>::max();
		for(auto [u, v, w]: edge){
			for(auto inter = 0; inter < n; ++ inter){
				ctmin(res, 1LL * w * (min(fw.dist[u][inter], fw.dist[v][inter]) + 2 + fw.dist[inter][0] + fw.dist[inter][n - 1]));
				debug(u, v, w, inter, res);
			}
			for(auto rep = 2; rep; -- rep){
				ctmin(res, 1LL * w * (fw.dist[u][0] + fw.dist[v][n - 1] + 1));
				debug(u, v, w, res);
				swap(u, v);
			}
		}
		cout << res << "\n";
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

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////