#include <bits/stdc++.h>
using namespace std;

template<int SZ>
struct number_theory{
	vector<int> lpf, prime, mu, phi; // least prime factor, primes, mobius function, totient function, number of multiples
	number_theory(): lpf(SZ + 1), mu(SZ + 1, 1), phi(SZ + 1, 1){ // O(SZ)
		for(int i = 2; i <= SZ; ++ i){
			if(!lpf[i]) lpf[i] = i, prime.push_back(i);
			if(i / lpf[i] % lpf[i]) mu[i] = -mu[i / lpf[i]], phi[i] = phi[i / lpf[i]] * (lpf[i] - 1);
			else mu[i] = 0, phi[i] = phi[i / lpf[i]] * lpf[i];
			for(int j = 0; j < int(prime.size()) && prime[j] <= lpf[i] && prime[j] * i <= SZ; ++ j) lpf[prime[j] * i] = prime[j];
		}
	}
};

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
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<typename Head, typename... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "----DEBUG BEGIN----\n[" << #__VA_ARGS__ << "]:", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	number_theory<100000> nt;
	int n;
	cin >> n;
	vector<int> a(n), pos(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
		pos[a[i]] = i;
	}
	vector<array<int, 2>> res;
	auto do_swap = [&](int i, int j){
		vector<array<int, 2>> temp;
		while(i != j){
			debug(i, j);
			int p = *-- upper_bound(nt.prime.begin(), nt.prime.end(), j - i + 1);
			debug(p);
			temp.push_back({i, i + p - 1});
			i += p - 1;
		}
		reverse(temp.begin(), temp.end());
		for(auto [i, j]: temp){
			res.push_back({i, j});
			swap(pos[a[i]], pos[a[j]]);
			swap(a[i], a[j]);
		}
	};
	for(auto i = 0; i < n; ++ i){
		debug(i);
		debug(a);
		debug(pos);
		do_swap(i, pos[i]);
	}
	cout << int(res.size()) << "\n";
	for(auto [i, j]: res){
		cout << i + 1 << " " << j + 1 << "\n";
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