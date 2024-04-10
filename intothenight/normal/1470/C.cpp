#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());

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
	// int n = 100000, k = 2;
	// vector<int> res(n, k), res_next(n);
	// int pos = rng() % n;
	// auto advance_res = [&](){
	// 	fill(res_next.begin(), res_next.end(), 0);
	// 	for(auto i = 0; i < n; ++ i){
	// 		if(i == pos){
	// 			res_next[i == n - 1 ? 0 : i + 1] += res[i];
	// 		}
	// 		else{
	// 			res_next[i == n - 1 ? 0 : i + 1] += res[i] + 1 >> 1;
	// 			res_next[i ? i - 1 : n - 1] += res[i] >> 1;
	// 		}
	// 	}
	// 	swap(res, res_next);
	// };
	// int qcnt = 0;
	// auto query = [&](int i){
	// 	cout << "Query #" << ++ qcnt << "\n";
	// 	cout << "? " << i + 1 << "\n";
	// 	int x = res[i];
	// 	advance_res();
	// 	cout << x << endl;
	// 	return x;
	// };
	// auto answer = [&](int i){
	// 	cout << "! " << i + 1 << "\n";
	// 	cout << "pos = " << pos + 1 << "\n";
	// 	exit(0);
	// };
	int n, k;
	cin >> n >> k;
	int qcnt = 0;
	auto query = [&](int i){
		if(++ qcnt == 1000){
			while(true){
				cout << "TLE ";
			}
		}
		i %= n;
		if(i < 0){
			i += n;
		}
		cout << "? " << i + 1 << endl;
		int x;
		cin >> x;
		return x;
	};
	auto answer = [&](int i){
		i %= n;
		if(i < 0){
			i += n;
		}
		cout << "! " << i + 1 << "\n";
		exit(0);
	};
	int i, x;
	while(true){
		i = rng() % n;
		if((x = query(i)) != k){
			break;
		}
	}
	if(x > k){
		-- i;
		while(query(i) != k){
			-- i;
		}
	}
	else{
		++ i;
		while(query(i) != k){
			++ i;
		}
	}
	answer(i);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////