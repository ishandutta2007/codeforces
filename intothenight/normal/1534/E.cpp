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
	int n, k;
	cin >> n >> k;
	if(n & 1 && ~k & 1){
		cout << "-1\n";
		return 0;
	}
	auto query = [&](vector<int> ind)->int{
		cout << "? ";
		for(auto i: ind){
			cout << i + 1 << " ";
		}
		cout << endl;
		int x;
		cin >> x;
		return x;
	};
	vector<int> ind(k);
	int res = 0;
	if(n % k == 0){
		int s = 0;
		while(s < n){
			iota(ind.begin(), ind.end(), s);
			res ^= query(ind);
			s += k;
		}
	}
	else if(k & 1){
		int s = 0;
		if(n & 1){
			iota(ind.begin(), ind.end(), s);
			res ^= query(ind);
			s += k;
		}
		while(s + 2 * k <= n){
			iota(ind.begin(), ind.end(), s);
			res ^= query(ind);
			s += k;
			iota(ind.begin(), ind.end(), s);
			res ^= query(ind);
			s += k;
		}
		while(s < n){
			int len = n - s;
			while(len / 2 + k > n){
				len -= 2;
			}
			vector<bool> flag(n);
			for(auto t = s; t < s + len; ++ t){
				flag[t] = true;
			}
			vector<int> rem;
			for(auto rep = 0, x = 0; rep < k - len / 2; ++ rep){
				while(flag[x]){
					++ x;
				}
				rem.push_back(x);
				++ x;
			}
			iota(ind.begin(), ind.begin() + len / 2, s);
			copy(rem.begin(), rem.end(), ind.begin() + len / 2);
			res ^= query(ind);
			s += len / 2;
			iota(ind.begin(), ind.begin() + len / 2, s);
			copy(rem.begin(), rem.end(), ind.begin() + len / 2);
			res ^= query(ind);
			s += len / 2;
		}
	}
	else{
		int s = 0;
		if(n < 2 * k){
			iota(ind.begin(), ind.end(), s);
			res ^= query(ind);
			s += k;
		}
		else{
			while(s + 2 * k <= n){
				iota(ind.begin(), ind.end(), s);
				res ^= query(ind);
				s += k;
			}
		}
		while(s < n){
			int len = n - s;
			while(len / 2 + k > n){
				len -= 2;
			}
			vector<bool> flag(n);
			for(auto t = s; t < s + len; ++ t){
				flag[t] = true;
			}
			vector<int> rem;
			for(auto rep = 0, x = 0; rep < k - len / 2; ++ rep){
				while(flag[x]){
					++ x;
				}
				rem.push_back(x);
				++ x;
			}
			debug(flag);
			debug(rem);
			debug(len);
			iota(ind.begin(), ind.begin() + len / 2, s);
			copy(rem.begin(), rem.end(), ind.begin() + len / 2);
			res ^= query(ind);
			s += len / 2;
			iota(ind.begin(), ind.begin() + len / 2, s);
			copy(rem.begin(), rem.end(), ind.begin() + len / 2);
			res ^= query(ind);
			s += len / 2;
		}
	}
	cout << "! " << res << "\n";
	return 0;
}

/*
010
001
111
101
110
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////