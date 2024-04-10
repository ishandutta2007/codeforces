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

vector<pair<long long, int>> factorize(long long x){
	vector<pair<long long, int>> res;
	for(long long p = 2; p * p <= x; ++ p){
		if(x % p == 0){
			res.push_back({p, 0});
			while(x % p == 0){
				++ res.back().second;
				x /= p;
			}
		}
	}
	if(x > 1) res.push_back({x, 1});
	return res;
}

long long modexp(long long b, long long e, const long long mod){
	long long res = 1;
	for(; e; e >>= 1, b = (__uint128_t) b * b % mod) if(e & 1) res = (__uint128_t) res * b % mod;
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	long long m, x;
	cin >> m >> x;
	auto fact = factorize(m);
	int k = int(fact.size());
	vector<vector<pair<long long, int>>> fact_of_p1(k);
	for(auto i = 0; i < k; ++ i){
		fact_of_p1[i] = factorize(fact[i].first - 1);
	}
	debug(fact_of_p1);
	long long res = 0;
	function<void(int)> solve = [&](int i){
		static vector<int> exp(k);
		static long long phi = 1, d = 1;
		if(i == k){
			static vector<pair<long long, int>> temp, fact_of_phi;
			temp.clear(), fact_of_phi.clear();
			for(auto i = 0; i < k; ++ i){
				if(exp[i]){
					temp.insert(temp.end(), fact_of_p1[i].begin(), fact_of_p1[i].end());
					if(exp[i] > 1){
						temp.push_back({fact[i].first, exp[i] - 1});
					}
				}
			}
			sort(temp.begin(), temp.end());
			//debug(temp);
			for(auto [p, e]: temp){
				if(fact_of_phi.empty() || fact_of_phi.back().first != p){
					fact_of_phi.push_back({p, e});
				}
				else{
					fact_of_phi.back().second += e;
				}
			}
			int phi_k = int(fact_of_phi.size());
			long long cur = numeric_limits<long long>::max() / 2;
			function<void(int)> solve_phi = [&](int i){
				static long long phi_d = 1;
				if(i == phi_k){
					//debug(phi_d);
					if(cur > phi_d && (d == 1 || modexp(x, phi_d, d) == 1)){
						cur = phi_d;
					}
					return;
				}
				long long prev_phi_d = phi_d;
				solve_phi(i + 1);
				for(auto e = 1; e <= fact_of_phi[i].second; ++ e){
					phi_d *= fact_of_phi[i].first;
					solve_phi(i + 1);
				}
				phi_d = prev_phi_d;
			};
			solve_phi(0);
			//debug(fact_of_phi);
			//debug(exp);
			//debug(d, phi, cur);
			res += phi / cur;
			return;
		}
		long long prev_phi = phi, prev_d = d;
		exp[i] = 0;
		solve(i + 1);
		exp[i] = 1;
		phi *= fact[i].first - 1;
		d *= fact[i].first;
		solve(i + 1);
		for(auto e = 2; e <= fact[i].second; ++ e){
			exp[i] = e;
			phi *= fact[i].first;
			d *= fact[i].first;
			solve(i + 1);
		}
		phi = prev_phi, d = prev_d;
	};
	solve(0);
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