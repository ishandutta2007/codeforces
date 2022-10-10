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

template<bool GET_MAX = true, typename T = long long>
void DCDP(auto &dp, auto &dp_next, auto &cost, int low, int high, int opt_low, int opt_high){
	if(low >= high) return;
	int mid = low + (high - low >> 1);
	pair<T, int> res{GET_MAX ? numeric_limits<T>::min() : numeric_limits<T>::max(), -1};
	for(int i = min(mid, opt_high) - 1; i >= opt_low; -- i) res = GET_MAX ? max(res, {dp[i] + cost(i, mid), i}) : min(res, {dp[i] + cost(i, mid), i});
	dp_next[mid] = res.first;
	DCDP<GET_MAX, T>(dp, dp_next, cost, low, mid, opt_low, res.second + 1), DCDP<GET_MAX, T>(dp, dp_next, cost, mid + 1, high, res.second, opt_high);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<double> pref(n + 1), ipref(n + 1);
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] = pref[i] + a[i];
		ipref[i + 1] = ipref[i] + 1.0 / a[i];
	}
	const double inf = numeric_limits<double>::max() / 10;
	vector<vector<double>> dp(k + 1, vector<double>(n + 1, inf)); // Min exp time to split first j into i
	dp[0][0] = 0;
	//  dp[i][j] = min{0 <= k < i}(dp[k][j - 1] + cost(k, i))
	for(auto i = 1; i <= k; ++ i){ // solve dp[i] from dp[i-1]
		double cur_cost = 0;
		int cost_l = 0, cost_r = 0;
		auto cost = [&](int i, int j){
			while(cost_l < i){
				// delete cost_l
				cur_cost -= a[cost_l] * (ipref[cost_r] - ipref[cost_l]);
				++ cost_l;
			}
			while(cost_l > i){
				-- cost_l;
				// insert cost_l
				cur_cost += a[cost_l] * (ipref[cost_r] - ipref[cost_l]);
			}
			while(cost_r < j){
				// insert cost_r
				cur_cost += (pref[cost_r + 1] - pref[cost_l]) / a[cost_r];
				++ cost_r;
			}
			while(cost_r > j){
				-- cost_r;
				// delete cost_r
				cur_cost -= (pref[cost_r + 1] - pref[cost_l]) / a[cost_r];
			}
			return cur_cost;
		};
		DCDP<false, double>(dp[i - 1], dp[i], cost, i, n + 1, 0, n + 1);
		debug(dp[i]);
	}
	cout << fixed << setprecision(15) << dp[k][n] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////