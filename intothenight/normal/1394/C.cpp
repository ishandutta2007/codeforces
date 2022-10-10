#include <bits/stdc++.h>
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

template<typename T, typename Pred>
T binary_search(T low, T high, Pred p, const bool &is_left = true){
	assert(low < high);
	while(high - low >= 2){
		auto mid = low + (high - low >> 1);
		(p(mid) == is_left ? low : high) = mid;
	}
	return is_left ? low : high;
}

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
	int n;
	cin >> n;
	using point = array<int, 2>;
	vector<point> a(n);
	for(auto i = 0; i < n; ++ i){
		string s;
		cin >> s;
		for(auto c: s){
			++ a[i][c == 'N']; // B = 0, N = 1
		}
	}
	auto dist = [&](const point &p, const point &q){
		if((p[0] < q[0]) == (p[1] < q[1])){
			return max(abs(p[0] - q[0]), abs(p[1] - q[1]));
		}
		else{
			return abs(p[0] - q[0]) + abs(p[1] - q[1]);
		}
	};
	auto calc = [&](int x, int y){
		return accumulate(a.begin(), a.end(), 0, [&](int s, auto p){ return max(s, dist(p, {x, y})); });
	};
	int resx = -1, resy = -1;
	const int minf = numeric_limits<int>::min(), inf = numeric_limits<int>::max();
	auto pred = [&](int d){
		array<int, 2> rx{minf, inf}, ry{minf, inf}, ryx{minf, inf};
		for(auto p: a){
			ctmax(rx[0], p[0] - d), ctmin(rx[1], p[0] + d);
			ctmax(ry[0], p[1] - d), ctmin(ry[1], p[1] + d);
			ctmax(ryx[0], p[1] - p[0] - d), ctmin(ryx[1], p[1] - p[0] + d);
		}
		debug(d, rx, ry, ryx);
		if(rx[0] > rx[1] || ry[0] > ry[1] || ryx[0] > ryx[1] || max(ry[0] - rx[1], ryx[0]) > min(ry[1] - rx[0], ryx[1])){
			debug(true);
			return false;
		}
		debug(false);
		resx = rx[1], resy = ry[1];
		if(resy - resx < ryx[0]){
			tie(resx, resy) = pair{ry[1] - ryx[0], ry[1]};
		}
		if(resy - resx > ryx[1]){
			tie(resx, resy) = pair{rx[1], rx[1] + ryx[1]};
		}
		return true;
	};
	int res = binary_search(-1, int(1e9), pred, false);
	pred(res);
	cout << res << "\n" << string(resx, 'B') + string(resy, 'N') << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////