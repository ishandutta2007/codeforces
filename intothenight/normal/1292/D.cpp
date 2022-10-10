#include "bits/stdc++.h"
using namespace std;

// DEBUG BEGIN
template<typename L, typename R>
ostream &operator<<(ostream &out, pair<L, R> p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<typename Tuple, size_t ...Is>
void print_tuple(ostream &out, Tuple t, index_sequence<Is...>){
	((out << (Is ? ", " : "") << get<Is>(t)), ...);
}
template<typename ...Args>
ostream &operator<<(ostream &out, tuple<Args...> t){
	out << "(", print_tuple(out, t, index_sequence_for<Args...>{}); return out << ")";
}
template<typename ...Args, template<typename...> typename T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, T<Args...> arr){
	out << "{"; for(auto &x: arr) out << x << " ";
	return out << (arr.size() ? "\b" : "") << "}";
}
template<size_t S>
ostream &operator<<(ostream &out, bitset<S> b){
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

array<vector<int>, 2> linearsieve(int n){
	vector<int> lpf(n + 1), prime;
	for(auto i = 2; i <= n; ++ i){
		if(!lpf[i]) lpf[i] = i, prime.push_back(i);
		for(auto j = 0; j < int(prime.size()) && prime[j] <= lpf[i] && i * prime[j] <= n; ++ j){
			lpf[i * prime[j]] = prime[j];
		}
	}
	return {lpf, prime};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	const int mx = 5000;
	auto [lpf, prime] = linearsieve(mx);
	int m = int(prime.size());
	vector<vector<int>> exp(mx + 1, vector<int>(m, 0));
	long long res = 0;
	for(auto i = 2; i <= mx; ++ i){
		for(auto j = 0; j < m; ++ j){
			for(auto x = i; x /= prime[j]; ){
				exp[i][j] += x;
			}
		}
	}
	int n;
	cin >> n;
	vector<int> cnt(mx + 1), pref(mx + 2);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		++ cnt[x];
	}
	for(auto i = 0; i <= mx; ++ i){
		pref[i + 1] = pref[i] + cnt[i];
	}
	vector<int> cur(m);
	for(auto t = m - 1, l = 0, r = mx + 1; t >= 0; -- t){
		int nl = l;
		while(pref[r] - pref[nl + 1] > n / 2){
			++ nl;
		}
		while(nl > l && exp[nl][t] == exp[nl - 1][t]){
			-- nl;
		}
		l = nl;
		cur[t] = exp[l][t];
		while(exp[r - 1][t] ^ exp[l][t]){
			-- r;
		}
		if(!t || pref[r] - pref[l] <= n / 2){
			res = 0;
			for(auto i = 0; i <= mx; ++ i){
				int j = m;
				while(j && exp[i][j - 1] == cur[j - 1]){
					-- j;
				}
				if(j){
					for(auto t = 0; t < j - 1; ++ t){
						res += 1LL * cnt[i] * (exp[i][t] + cur[t]);
					}
					res += 1LL * cnt[i] * abs(exp[i][j - 1] - cur[j - 1]);
				}
			}
			break;
		}
		debug(prime[t], l, r, exp[l][t], res);
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