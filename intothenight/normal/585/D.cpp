#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
	vector<int> p3{1};
	for(auto i = 0; i < 16; ++ i){
		p3.push_back(p3.back() * 3);
	}
	int n;
	cin >> n;
	array<int, 2> sz{n / 2, n - n / 2};
	array<vector<array<int, 3>>, 2> a{vector<array<int, 3>>(sz[0]), vector<array<int, 3>>(sz[1])};
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < 3; ++ j){
			if(i < n / 2){
				cin >> a[0][i][j];
			}
			else{
				cin >> a[1][i - n / 2][j];
			}
		}
	}
	vector<array<array<int, 2>, 2>> half;
	const int minf = numeric_limits<int>::min() / 2, inf = numeric_limits<int>::max() / 2;
	array<int, 3> res{minf, -1, -1};
	auto cmp = [&](auto &x, auto &y){
		return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
	};
	function<void(int, int, const bool &)>
	solve = [&](int i, int mask, const bool &type){
		static array<int, 3> sum{};
		if(i == sz[type]){
			if(!type){
				half.push_back({{{sum[1] - sum[0], sum[2] - sum[0]}, {sum[0], mask}}});
			}
			else{
				int j = lower_bound(half.begin(), half.end(), array<array<int, 2>, 2>({{{sum[0] - sum[1], sum[0] - sum[2]}, {inf, 0}}}), cmp) - half.begin();
				if(j != int(half.size()) && half[j][0] == array<int, 2>{sum[0] - sum[1], sum[0] - sum[2]}){
					ctmax(res, array<int, 3>{half[j][1][0] + sum[0], half[j][1][1], mask});
				}
			}
			return;
		}
		for(auto tit = 0; tit < 3; ++ tit){
			sum[tit] += a[type][i][tit];
			sum[tit == 2 ? 0 : tit + 1] += a[type][i][tit == 2 ? 0 : tit + 1];
			solve(i + 1, mask + p3[i] * tit, type);
			sum[tit] -= a[type][i][tit];
			sum[tit == 2 ? 0 : tit + 1] -= a[type][i][tit == 2 ? 0 : tit + 1];
		}
	};
	solve(0, 0, 0);
	sort(half.begin(), half.end(), cmp);
	debug(half);
	solve(0, 0, 1);
	if(res[0] == minf){
		cout << "Impossible\n";
	}
	else{
		string trans("LMW");
		for(auto type = 0; type < 2; ++ type){
			for(auto i = 0, temp = res[type + 1]; i < sz[type]; ++ i, temp /= 3){
				int tit = temp % 3;
				cout << trans[tit] << trans[tit == 2 ? 0 : tit + 1] << "\n";
			}
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