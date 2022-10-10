#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
	int n, d;
	cin >> n >> d;
	array<vector<int>, 10> occur;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		occur[x % 10].push_back(x);
	}
	array<vector<long double>, 10> lgsum;
	for(auto rem = 0; rem < 10; ++ rem){
		sort(occur[rem].rbegin(), occur[rem].rend());
		vector<long double> sum((int)occur[rem].size() + 1);
		for(auto i = 0; i < (int)occur[rem].size(); ++ i){
			sum[i + 1] = sum[i] + log(occur[rem][i]);
		}
		debug(rem);
		debug(occur[rem]);
		debug(sum);
		lgsum[rem].push_back(0);
		for(auto r = 1; r <= 4; ++ r){
			if(r <= (int)occur[rem].size()){
				lgsum[rem].push_back(sum[r + ((int)occur[rem].size() - r) / 4 * 4]);
			}
		}
	}
	pair<long double, array<int, 10>> res{-1, {}};
	debug(res);
	auto solve = [&](int rem, auto solve){
		static array<int, 10> state{};
		static long double sum = 0;
		static int remainder = 1;
		if(rem == 10){
			debug(state, sum, remainder);
			if(remainder == d && sum > 1e-6){
				ctmax(res, pair{sum, state});
			}
			return;
		}
		int prev = remainder;
		for(auto x = 0; x < (int)lgsum[rem].size(); ++ x){
			state[rem] = x;
			sum += lgsum[rem][x];
			solve(rem + 1, solve);
			remainder = remainder * rem % 10;
			sum -= lgsum[rem][x];
		}
		remainder = prev;
	};
	solve(0, solve);
	debug(res);
	if(res.first < 0){
		cout << "-1\n";
		return 0;
	}
	auto state = res.second;
	vector<int> ans;
	for(auto rem = 0; rem < 10; ++ rem){
		if(state[rem]){
			int sz = state[rem] + ((int)occur[rem].size() - state[rem]) / 4 * 4;
			ans.insert(ans.end(), occur[rem].begin(), occur[rem].begin() + sz);
		}
	}
	cout << (int)ans.size() << "\n";
	for(auto x: ans){
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