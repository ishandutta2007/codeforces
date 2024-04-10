#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		for(auto i = 0; i < m; ++ i){
			cin >> b[i];
		}
		int pa = 0, pb = 0;
		while(pa < n && a[pa] < 0){
			++ pa;
		}
		while(pb < m && b[pb] < 0){
			++ pb;
		}
		reverse(a.begin(), a.begin() + pa);
		for(auto i = 0; i < pa; ++ i){
			a[i] = -a[i];
		}
		reverse(b.begin(), b.begin() + pb);
		for(auto i = 0; i < pb; ++ i){
			b[i] = -b[i];
		}
		debug(n, m);
		debug(a);
		debug(b);
		int res = 0;
		for(auto rep = 0; rep < 2; ++ rep){
			if(pa){
				debug(rep, pa, pb);
				vector<int> suff(pa + 1);
				for(auto i = pa - 1; i >= 0; -- i){
					suff[i] = suff[i + 1];
					if(binary_search(b.begin(), b.begin() + pb, a[i])){
						++ suff[i];
					}
				}
				int cur = 0;
				for(auto len = 1, jl = 0, jr = 0; len <= pa; ++ len){
					int l = a[len - 1] - (len - 1);
					int r = len == pa ? numeric_limits<int>::max() : a[len] - len;
					while(jl < pb && b[jl] < l){
						++ jl;
					}
					while(jl < pb && b[jl] < r){
						while(jr < pb && (jr < jl || b[jr] - b[jl] < len)){
							++ jr;
						}
						debug(jl, jr);
						ctmax(cur, jr - jl + suff[len]);
						++ jl;
					}
				}
				res += cur;
			}
			rotate(a.begin(), a.begin() + pa, a.end());
			rotate(b.begin(), b.begin() + pb, b.end());
			pa = n - pa;
			pb = m - pb;
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