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
template<class T> ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "----DEBUG BEGIN----\n[" << #__VA_ARGS__ << "]:", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	string s;
	cin >> s;
	int n = (int)s.size();
	array<int, 26> acnt{};
	for(auto c: s){
		++ acnt[c - 'a'];
	}
	debug(acnt);
	array<array<vector<int>, 26>, 26> cnt;
	for(auto c = 0; c < 26; ++ c){
		for(auto d = 0; d < 26; ++ d){
			cnt[c][d].assign(n, 0);
		}
	}
	for(auto i = 0; i < n; ++ i){
		for(auto j = i + 1; j < n; ++ j){
			++ cnt[s[i] - 'a'][s[j] - 'a'][j - i];
			++ cnt[s[j] - 'a'][s[i] - 'a'][i - j + n];
		}
	}
	double res = 0;
	for(auto c = 0; c < 26; ++ c){
		if(acnt[c]){
			double mx = 0;
			for(auto l = 1; l < n; ++ l){
				int t = 0, tot = 0;
				for(auto d = 0; d < 26; ++ d){
					if(cnt[c][d][l] == 1){
						++ t;
					}
					tot += cnt[c][d][l];
				}
				mx = max(mx, 1.0 * t / tot);
				debug(l, mx, t, tot);
			}
			debug(c, acnt[c], mx);
			res += mx * acnt[c] / n;
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////