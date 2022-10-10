#include <bits/stdc++.h>
using namespace std;

template<class T>
struct fenwick_tree{
	int n;
	vector<T> data;
	fenwick_tree(){ }
	// O(n)
	fenwick_tree(int n): n(n), data(n){ }
	// O(n)
	fenwick_tree(int n, T init): fenwick_tree(vector<T>(n, init)){ }
	// O(n)
	fenwick_tree(const vector<T> &v): n((int)v.size()), data(v){
		for(auto i = 1; i <= n; ++ i) if(i + (i & -i) <= n) data[i + (i & -i) - 1] += data[i - 1];
	}
	fenwick_tree(const fenwick_tree &otr): n(otr.n), data(otr.data){
	}
	// O(log n)
	void update(int p, T x){
		assert(0 <= p && p < n);
		for(++ p; p <= n; p += p & -p) data[p - 1] += x;
	}
	// O(log n)
	T query(int r) const{
		T s{};
		for(; r > 0; r -= r & -r) s += data[r - 1];
		return s;
	}
	// O(log n)
	T query(int l, int r) const{
		assert(0 <= l && l <= r && r <= n);
		return query(r) - query(l);
	}
	// f(sum[0, r)) is T, T, ..., T, F, F, ..., F, returns min r with F (n + 1 if no such r)
	// O(log n)
	int max_pref(auto f) const{
		if(!f({})) return 0;
		int p = 0;
		T pref{};
		for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && f(pref + data[p + pw - 1])){
			pref += data[p + pw - 1];
			p += pw;
		}
		return p + 1;
	}
	int lower_bound(T x) const{
		if(x <= T{}) return 0;
		int p = 0;
		T pref{};
		for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && pref + data[p + pw - 1] < x){
			pref += data[p + pw - 1];
			p += pw;
		}
		return p + 1;
	}
	int upper_bound(T x) const{
		if(x < T{}) return 0;
		int p = 0;
		T pref{};
		for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && pref + data[p + pw - 1] <= x){
			pref += data[p + pw - 1];
			p += pw;
		}
		return p + 1;
	}
};

// O(n log n)
// Requires fenwick_tree
template<class T, class Compare = less<>>
long long count_inversions(const vector<T> &a, bool count_equal = false, Compare cmp = less<>()){
	int n = (int)a.size();
	vector<T> cmpr = a;
	sort(cmpr.begin(), cmpr.end(), cmp);
	fenwick_tree<int> rsumq(n);
	long long res = 0;
	for(auto x: a){
		int i = lower_bound(cmpr.begin(), cmpr.end(), x, cmp) - cmpr.begin();
		res += rsumq.query(i + !count_equal, n);
		rsumq.update(i, 1);
	}
	return res;
}

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
ostream &operator<<(ostream &out, __int128_t x){
	if(!x) return out << 0;
	if(x < 0) out << "-", x = -x;
	array<int, 5> a{};
	int block = 29, it = 0;
	while(x) a[it ++] = x & (1 << block) - 1, x >>= block;
	while(it --) out << a[it];
	return out;
}
ostream &operator<<(ostream &out, __uint128_t x){
	if(!x) return out << 0;
	array<int, 5> a{};
	int block = 29, it = 0;
	while(x) a[it ++] = x & (1 << block) - 1, x >>= block;
	while(it --) out << a[it];
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
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		array<int, 2> cnt{};
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			++ cnt[a[i] &= 1];
		}
		long long res = numeric_limits<long long>::max();
		if(n & 1){
			if(cnt[0] != n + 1 >> 1 && cnt[1] != n + 1 >> 1){
				cout << "-1\n";
				return 0;
			}
			int s = cnt[1] == n + 1 >> 1;
			vector<int> pos(n);
			array<int, 2> ind{};
			for(auto i = 0; i < n; ++ i){
				pos[i] = ind[a[i]] << 1 | (s != a[i]);
				++ ind[a[i]];
			}
			debug(pos);
			ctmin(res, count_inversions(pos));
		}
		else{
			if(cnt[0] != n / 2 && cnt[1] != n / 2){
				cout << "-1\n";
				return 0;
			}
			for(auto s = 0; s < 2; ++ s){
				vector<int> pos(n);
				array<int, 2> ind{};
				for(auto i = 0; i < n; ++ i){
					pos[i] = ind[a[i]] << 1 | (s != a[i]);
					++ ind[a[i]];
				}
				ctmin(res, count_inversions(pos));
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