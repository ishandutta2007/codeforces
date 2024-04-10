#include "bits/stdc++.h"
using namespace std;

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
	int n;
	cin >> n;
	vector<int> p{1};
	for(auto i = 0; i < 8; ++ i){
		p.push_back(p.back() * 10);
	}
	vector<int> res;
	auto solve = [&](int x, int y){
		debug(x, y);
		const int mx = 1e7;
		for(auto i = 0; i < mx; ++ i){
			int cur = x * (p[8] + 1) + y * (p[7] + 1);
			for(auto d = 0, t = i; d < 7; ++ d, t /= 10){
				cur += t % 10 * (p[d] + 1);
			}
			if(cur == n){
				res.push_back(i + x * p[8] + y * p[7]);
			}
		}
	};
	debug(p);
	int q8 = n / (p[8] + 1);
	int q7 = n % (p[8] + 1) / (p[7] + 1);
	solve(q8, q7);
	if(q7){
		solve(q8, q7 - 1);
	}
	if(q8){
		q7 = (n % (p[8] + 1) + p[8] + 1) / (p[7] + 1);
		if(q7 < 10){
			solve(q8 - 1, q7);
		}
		if(q7 <= 10 && q7){
			solve(q8 - 1, q7 - 1);
		}
	}
	sort(res.begin(), res.end()), res.erase(unique(res.begin(), res.end()), res.end());
	cout << int(res.size()) << "\n";
	for(auto x: res){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////