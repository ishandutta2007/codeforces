#include <bits/stdc++.h>
using namespace std;
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
		int n, m;
		cin >> n >> m;
		vector<long long> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector<vector<array<long long, 2>>> segs(n + 1);
		for(auto i = 0; i < m; ++ i){
			long long l, r;
			cin >> l >> r;
			int p = lower_bound(a.begin(), a.end(), l) - a.begin();
			if(p < n && a[p] <= r){
				continue;
			}
			segs[p].push_back({l, r});
		}
		for(auto i = 0; i <= n; ++ i){
			sort(segs[i].begin(), segs[i].end());
		}
		debug(a);
		debug2(segs);
		debug("\n");
		const long long inf = numeric_limits<long long>::max() / 3;
		vector<pair<long long, long long>> lc;
		vector<long long> pref, suff;
		{
			long long left = 0;
			for(auto [l, r]: segs[0]){
				left = max(left, a[0] - r);
			}
			lc.push_back({left, 0LL});
			pref = {inf, 2 * left};
			suff = {left, inf};
		}
		auto get = [&](long long req)->long long{
			int p = lower_bound(lc.begin(), lc.end(), pair{req, 0LL}) - lc.begin();
			return min(pref[p] + req, suff[p] + 2 * req);
		};
		debug(lc);
		debug(pref);
		debug(suff);
		debug("\n");
		for(auto i = 1; i < n; ++ i){
			vector<pair<long long, long long>> lc_next((int)segs[i].size() + 1);
			{
				vector<long long> rsuff((int)segs[i].size() + 1);
				for(auto j = (int)segs[i].size() - 1; j >= 0; -- j){
					rsuff[j] = max(rsuff[j + 1], a[i] - segs[i][j][1]);
				}
				long long left = 0;
				for(auto j = 0; j < (int)segs[i].size(); ++ j){
					lc_next[j] = {rsuff[j], get(j ? segs[i][j - 1][0] - a[i - 1] : 0)};
				}
				lc_next[(int)segs[i].size()] = {0, get(segs[i].empty() ? 0 : segs[i].back()[0] - a[i - 1])};
				reverse(lc_next.begin(), lc_next.end());
			}
			vector<long long> pref_next((int)lc_next.size() + 1, inf), suff_next((int)lc_next.size() + 1, inf);
			for(auto i = 0; i < (int)lc_next.size(); ++ i){
				auto [l, c] = lc_next[i];
				pref_next[i + 1] = min(pref_next[i], 2LL * l + c);
			}
			for(auto i = (int)lc_next.size() - 1; i >= 0; -- i){
				auto [l, c] = lc_next[i];
				suff_next[i] = min(suff_next[i + 1], l + c);
			}
			swap(lc, lc_next);
			swap(pref, pref_next);
			swap(suff, suff_next);
			debug(i);
			debug(lc);
			debug(pref);
			debug(suff);
			debug("\n");
		}
		{
			long long right = 0;
			for(auto [l, r]: segs[n]){
				right = max(right, l - a[n - 1]);
			}
			cout << get(right) << "\n";
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

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////