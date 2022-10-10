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
	int n, w, h;
	cin >> n >> w >> h;
	map<int, pair<vector<pair<int, int>>, vector<pair<int, int>>>> a; // vertical, horizontal
	for(auto i = 0; i < n; ++ i){
		int g, p, t;
		cin >> g >> p >> t;
		if(g == 1){
			a[p - t].first.push_back({p, i});
		}
		else{
			a[p - t].second.push_back({p, i});
		}
	}
	vector<pair<int, int>> res(n);
	for(auto [sum, state]: a){
		sort(state.first.begin(), state.first.end());
		sort(state.second.rbegin(), state.second.rend());
		debug(sum);
		debug(state.first);
		debug(state.second);
		vector<pair<int, int>> cur;
		for(auto [p, i]: state.first){
			cur.push_back({p, h});
		}
		for(auto [p, i]: state.second){
			cur.push_back({w, p});
		}
		debug(cur);
		for(auto i = 0; i < (int)state.second.size(); ++ i){
			res[state.second[i].second] = cur[i];
		}
		for(auto i = 0; i < (int)state.first.size(); ++ i){
			res[state.first[i].second] = cur[i + (int)state.second.size()];
		}
	}
	for(auto [x, y]: res){
		cout << x << " " << y << "\n";
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