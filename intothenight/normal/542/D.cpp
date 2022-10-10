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
	long long A;
	cin >> A;
	vector<long long> divs;
	vector<int> isolatable;
	vector<long long> rep_p;
	vector<vector<int>> ddivs;
	for(auto low = 1LL, d = 1LL; low <= A; low = d + 1){
		d = A / (A / low);
		if(A % d == 0){
			divs.push_back(d);
			ddivs.emplace_back();
			for(auto i = 0; i < (int)divs.size(); ++ i){
				if(d % divs[i] == 0){
					ddivs.back().push_back(i);
				}
			}
			debug(d, ddivs.back());
			if(d <= 2){
				isolatable.push_back(false);
				rep_p.push_back(-1);
			}
			else{
				long long x = d - 1, p = -1;
				for(auto q = 2LL; q * q <= x; ++ q){
					if(x % q == 0){
						p = q;
						break;
					}
				}
				if(!~p){
					p = x;
				}
				rep_p.push_back(p);
				while(x % p == 0){
					x /= p;
				}
				isolatable.push_back(x == 1);
			}
		}
	}
	debug(divs);
	debug(isolatable);
	vector<long long> primes = rep_p;
	sort(primes.begin(), primes.end()), primes.erase(unique(primes.begin(), primes.end()), primes.end());
	if(!primes.empty() && !~primes[0]) primes.erase(primes.begin());
	for(auto &p: rep_p){
		if(~p){
			p = lower_bound(primes.begin(), primes.end(), p) - primes.begin();
		}
	}
	debug(primes);
	int np = (int)primes.size(), n = (int)divs.size();
	vector<vector<long long>> dp(n, vector<long long>(np + 1)); // dp[i][x]: # of ways making i using primes up to primes[x-1]
	fill(dp[0].begin(), dp[0].end(), 1);
	for(auto i = 1; i < n; ++ i){
		for(auto t = 1; t < (int)ddivs[i].size(); ++ t){
			int j = ddivs[i][t], k = ddivs[i][(int)ddivs[i].size() - 1 - t];
			if(isolatable[j]){
				int p = rep_p[j];
				dp[i][p + 1] += dp[k][p];
			}
		}
		for(auto p = 0; p < np; ++ p){
			dp[i][p + 1] += dp[i][p];
		}
	}
	debug2(dp);
	cout << dp[n - 1][np] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////