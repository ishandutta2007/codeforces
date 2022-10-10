#include <bits/stdc++.h>
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

// DEBUG BEGIN
#ifdef LOCAL
template<typename L, typename R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<typename Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<typename Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<typename... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<typename ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<typename T> ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<typename Head, typename... Tail>
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
	vector<array<int, 2>> rob(n), srch(m);
	vector<int> cmpr;
	for(auto i = 0; i < n; ++ i){
		cin >> rob[i][0] >> rob[i][1];
		cmpr.push_back(rob[i][0]);
		cmpr.push_back(rob[i][1]);
	}
	for(auto i = 0; i < m; ++ i){
		cin >> srch[i][0] >> srch[i][1];
		cmpr.push_back(srch[i][0]);
		cmpr.push_back(srch[i][1]);
	}
	vector<array<int, 2>> bad;
	for(auto [x, y]: rob){
		for(auto [xx, yy]: srch){
			if(x <= xx && y <= yy){
				bad.push_back({xx - x, yy - y});
			}
		}
	}
	sort(bad.begin(), bad.end()), bad.erase(unique(bad.begin(), bad.end()), bad.end());
	debug(bad);
	vector<array<int, 2>> t{{-1, numeric_limits<int>::max()}};
	for(auto [x, y]: bad){
		while(t.back()[1] <= y){
			t.pop_back();
		}
		if(t.back()[0] < x){
			t.push_back({x, y});
		}
	}
	t.push_back({numeric_limits<int>::max(), -1});
	debug(t);
	int res = numeric_limits<int>::max();
	for(auto i = 1; i < (int)t.size(); ++ i){
		auto [x, y] = t[i - 1];
		auto [xx, yy] = t[i];
		ctmin(res, x + 1 + yy + 1);
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