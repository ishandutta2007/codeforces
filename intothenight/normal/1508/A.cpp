#include <bits/stdc++.h>
using namespace std;

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
		int n;
		cin >> n;
		array<string, 3> a;
		array<array<int, 2>, 3> cnt;
		for(auto i = 0; i < 3; ++ i){
			cin >> a[i];
			cnt[i][0] = count(a[i].begin(), a[i].end(), '0');
			cnt[i][1] = 2 * n - cnt[i][0];
		}
		for(auto i = 0; i < 3; ++ i){
			int j = (i + 1) % 3;
			for(auto bit = 0; bit < 2; ++ bit){
				if(cnt[i][bit] >= n && cnt[j][bit] >= n){
					debug(a[i], a[j], bit, cnt[i], cnt[j]);
					if(cnt[i][bit] < cnt[j][bit]){
						a[i] += string(cnt[j][bit] - cnt[i][bit], '0' + bit);
						cnt[i][bit] = cnt[j][bit];
					}
					else{
						a[j] += string(cnt[i][bit] - cnt[j][bit], '0' + bit);
						cnt[j][bit] = cnt[i][bit];
					}
					debug(a[i], a[j], bit, cnt[i], cnt[j]);
					string res;
					int p = 0, q = 0;
					for(auto x = 0; x < cnt[i][bit]; ++ x){
						array<int, 2> cur{};
						while(a[i][p] != '0' + bit){
							++ p;
							++ cur[0];
						}
						while(a[j][q] != '0' + bit){
							++ q;
							++ cur[1];
						}
						res += string(max(cur[0], cur[1]), '0' + !bit) + char(bit + '0');
						++ p, ++ q;
					}
					debug(p, q);
					res += string(max((int)a[i].size() - p, (int)a[j].size() - q), '0' + !bit);
					debug(res);
					cout << res << "\n";
					assert((int)res.size() <= 3 * n);
					return 0;
				}
			}
		}
		assert(false);
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