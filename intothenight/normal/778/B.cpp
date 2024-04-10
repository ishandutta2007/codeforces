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
	int n, m;
	cin >> n >> m;
	vector<tuple<int, string, int>> a(n); // name, val or name, op1, op, op2
	map<string, int> prev;
	for(auto i = 0; i < n; ++ i){
		string s;
		cin >> s;
		prev[s] = i;
		cin >> s >> s;
		auto &[x, op, y] = a[i];
		if(s[0] != '0' && s[0] != '1'){
			x = s == "?" ? -1 : prev[s];
			cin >> op >> s;
			y = s == "?" ? -1 : prev[s];
		}
		else{
			x = -2, op = s;
		}
	} // -2 indicates const, -1 indicate variable
	debug2(a);
	string minres, maxres;
	for(auto bit = 0; bit < m; ++ bit){
		array<int, 2> cnt{};
		static vector<int> cur(n);
		for(auto x = 0; x < 2; ++ x){
			for(auto i = 0; i < n; ++ i){
				auto &[val1, op, val2] = a[i];
				if(val1 == -2){
					if(op[bit] == '1'){
						++ cnt[x];
					}
					cur[i] = op[bit] - '0';
					debug("HERE1", val1, op, val2, cnt);
				}
				else{
					int u, v, w;
					u = val1 == -1 ? x : cur[val1];
					v = val2 == -1 ? x : cur[val2];
					if(op == "AND"){
						w = u & v;
					}
					else if(op == "OR"){
						w = u | v;
					}
					else{
						w = u ^ v;
					}
					if(w){
						++ cnt[x];
					}
					cur[i] = w;
					debug("HERE2", val1, op, val2, cnt);
				}
				debug(cur);
			}
			debug(bit, x, prev);
		}
		debug(cnt);
		if(cnt[0] < cnt[1]){
			minres.push_back('0'), maxres.push_back('1');
		}
		else if(cnt[0] == cnt[1]){
			minres.push_back('0'), maxres.push_back('0');
		}
		else{
			minres.push_back('1'), maxres.push_back('0');
		}
	}
	cout << minres << "\n" << maxres << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////