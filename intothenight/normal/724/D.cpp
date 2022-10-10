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
	int m;
	string s;
	cin >> m >> s;
	int n = (int)s.size();
	for(auto c = 'a'; c <= 'z'; ++ c){
		vector<int> pos{-1};
		for(auto i = 0; i < n; ++ i){
			if(s[i] <= c){
				pos.push_back(i);
			}
		}
		pos.push_back(n);
		bool ok = true;
		for(auto i = 0; i < (int)pos.size() - 1; ++ i){
			if(pos[i + 1] - pos[i] > m){
				ok = false;
				break;
			}
		}
		if(ok){
			debug(c);
			string res;
			for(auto i = 0; i < n; ){
				int j = i;
				vector<int> pos;
				while(j < n && s[j] >= c){
					if(s[j] == c){
						pos.push_back(j);
					}
					++ j;
				}
				debug(i, j);
				for(auto p = i - 1; ; ){
					if(p + m >= j){
						break;
					}
					debug(p);
					for(auto t = p + m; ; -- t){
						debug(c, t, s[t]);
						if(s[t] == c){
							res.push_back(c);
							p = t;
							break;
						}
					}
				}
				i = j;
				while(i < n && s[i] < c){
					res.push_back(s[i]);
					++ i;
				}
			}
			sort(res.begin(), res.end());
			cout << res << "\n";
			return 0;
		}
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