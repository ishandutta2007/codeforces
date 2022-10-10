#include "bits/stdc++.h"
using namespace std;

template<typename Pred>
long long custom_binary_search(long long low, long long high, Pred p, const bool &is_left = true){
	assert(low < high);
	while(high - low > 1){
		auto mid = low + (high - low >> 1);
		(p(mid) == is_left ? low : high) = mid;
	}
	return is_left ? low : high;
}

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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	int x0, y0, x1, y1, n;
	string s;
	cin >> x0 >> y0 >> x1 >> y1 >> n >> s;
	vector<int> trans(300);
	trans['U'] = 1, trans['L'] = 2, trans['D'] = 3;
	auto pred = [&](long long d){
		long long q = d / n;
		int rem = d % n;
		array<long long, 2> cur{x0, y0};
		for(auto i = 0; i < n; ++ i){
			auto [dx, dy] = dr[trans[s[i]]];
			cur[0] += dx * (q + (i < rem)), cur[1] += dy * (q + (i < rem));
		}
		return abs(cur[0] - x1) + abs(cur[1] - y1) <= d;
	};
	if(!pred(4e18)){
		cout << "-1\n";
	}
	else{
		cout << custom_binary_search(-1, 4e18, pred, false) << "\n";
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