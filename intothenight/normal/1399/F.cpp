#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

// DEBUG BEGIN
template<typename L, typename R> ostream &operator<<(ostream &out, pair<L, R> p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<typename... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<typename ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<typename ...Args, template<typename...> typename T> ostream &operator<<(enable_if_t<!is_same<T<Args...>, string>::value, ostream> &out, T<Args...> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<typename T, size_t N> ostream &operator<<(ostream &out, array<T, N> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, bitset<S> b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// DEBUG END

struct segment_tree{
	int n;
	vector<int> roots;

	using Q = int; // Query Type
	Q merge(const Q &lval, const Q &rval, int l, int m, int r){
		return max(lval, rval);
	} // merge two nodes representing the intervals [l, m) and [m, r)
	Q id{};
	Q init(int p){
		return id;
	}

	vector<array<int, 2>> range; // Node u represents the range range[u] = [l, r)
	vector<Q> val;
	void init_range(){
		for(int i = n; i < n << 1; ++ i) range[i] = {i - n, i - n + 1};
		for(int i = n - 1; i > 0; -- i) range[i] = {range[i << 1][0], range[i << 1 | 1][1]};
	}
	void build(int l, int r){
		for(l += n, r += n - 1; l > 1; ){
			l >>= 1, r >>= 1;
			for(int i = r; i >= l; -- i) val[i] = merge(val[i << 1], val[i << 1 | 1], range[i << 1][0], range[i << 1][1], range[i << 1 | 1][1]);
		}
	}
	Q operator[](int p) const{
		return val[p + n];
	}
	template<typename IT>
	segment_tree(IT begin, IT end): n(distance(begin, end)), range(n << 1), val(n << 1, id){
		init_range();
		for(int i = 0; i < n; ++ i) val[i + n] = *(begin ++);
		build(0, n);
	}
	segment_tree(int n): n(n), range(n << 1), val(n << 1, id){
		init_range();
		for(int i = 0; i < n; ++ i) val[i + n] = init(i);
		build(0, n);
	}
	void init_roots(){
		vector<int> roots_r;
		for(auto l = n, r = n << 1; l < r; l >>= 1, r >>= 1){
			if(l & 1) roots.push_back(l ++);
			if(r & 1) roots_r.push_back(-- r);
		}
		roots.insert(roots.end(), roots_r.rbegin(), roots_r.rend());
	}
	void update(int p, Q x){
		for(val[p += n] = x; p >>= 1; ) val[p] = merge(val[p << 1], val[p << 1 | 1], range[p << 1][0], range[p << 1][1], range[p << 1 | 1][1]);
	}
	Q query(int ql, int qr){
		if(ql >= qr) return id;
		int mid;
		Q res_l = id, res_r = id;
		for(int l = ql + n, r = qr + n; l < r; l >>= 1, r >>= 1){
			if(l & 1) res_l = merge(res_l, val[l], ql, range[l][0], range[l][1]), mid = range[l][1], ++ l;
			if(r & 1) -- r, res_r = merge(val[r], res_r, range[r][0], range[r][1], qr), mid = range[r][0];
		}
		return merge(res_l, res_r, ql, mid, qr);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<array<int, 2>> a(n + 1);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i][0] >> a[i][1], -- a[i][0];
		}
		a[n] = {0, int(4e5)};
		sort(a.begin(), a.end(), [&](auto p, auto q){ return pair{p[1], p[0]} < pair{q[1], q[0]}; });
		vector<vector<int>> adj(n + 1);
		for(auto u = 0; u <= n; ++ u){
			for(auto v = 0; v <= n; ++ v){
				if(u ^ v && a[u][0] <= a[v][0] && a[v][1] <= a[u][1]){
					adj[u].push_back(v);
				}
			}
		}
		vector<int> solve_dp(n + 1, -1);
		function<int(int)> solve = [&](int u){
			if(~solve_dp[u]) return solve_dp[u];
			vector<int> cmpr;
			for(auto v: adj[u]){
				cmpr.insert(cmpr.end(), {a[v][0], a[v][1]});
			}
			sort(cmpr.begin(), cmpr.end()), cmpr.erase(unique(cmpr.begin(), cmpr.end()), cmpr.end());
			int maxv = int(cmpr.size());
			auto ind = [&](int x){
				return lower_bound(cmpr.begin(), cmpr.end(), x) - cmpr.begin();
			};
			segment_tree tr(maxv);
			for(auto v: adj[u]){
				int l = ind(a[v][0]), r = ind(a[v][1]);
				int x = tr.query(0, l + 1) + solve(v) + 1;
				if(tr[r] < x){
					tr.update(r, x);
				}
			}
			return solve_dp[u] = tr.query(0, maxv);
		};
		cout << solve(n) << "\n";
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