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
	int n;
	cin >> n;
	vector<int> a(n), bad(n - 1);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	auto check = [&](int i){
		return i & 1 ? a[i] > a[i + 1] : a[i] < a[i + 1];
	};
	for(auto i = 0; i < n - 1; ++ i){
		bad[i] = !check(i);
	}
	vector<array<int, 2>> br;
	for(auto i = 0; i < n - 1; ){
		while(i < n - 1 && !bad[i]){
			++ i;
		}
		if(i < n - 1){
			int j = i;
			while(j < n - 1 && bad[j]){
				++ j;
			}
			br.push_back({i, j});
			i = j;
		}
	}
	auto test = [&](int i, int j){
		swap(a[i], a[j]);
		bool res = true;
		if(i && !check(i - 1) || i < n - 1 && !check(i) || j && !check(j - 1) || j < n - 1 && !check(j)){
			res = false;
		}
		swap(a[i], a[j]);
		return res;
	};
	debug(br);
	if((int)br.size() >= 3){
		cout << "0\n";
	}
	else if((int)br.size() == 2){
		auto [l1, r1] = br[0];
		auto [l2, r2] = br[1];
		if(r1 - l1 > 2 || r2 - l2 > 2){
			cout << "0\n";
		}
		else{
			int res = 0;
			for(auto i = r1 - 1; i <= l1 + 1; ++ i){
				for(auto j = r2 - 1; j <= l2 + 1; ++ j){
					res += test(i, j);
				}
			}
			cout << res << "\n";
		}
	}
	else{
		auto [l, r] = br[0];
		if(r - l > 4){
			cout << "0\n";
		}
		else if(r - l > 2){
			if(r - l == 4){
				cout << test(l + 1, r) << "\n";
			}
			else{
				int res = 0;
				for(auto i = l; i <= l + 1; ++ i){
					for(auto j = r - 1; j <= r; ++ j){
						res += test(i, j);
					}
				}
				cout << res << "\n";
			}
		}
		else{
			int res = 0;
			set<array<int, 2>> used;
			for(auto i = 0; i < n; ++ i){
				for(auto j = r - 1; j <= l + 1; ++ j){
					if(i != j && !used.count({i, j})){
						used.insert({i, j}), used.insert({j, i});
						res += test(i, j);
						if(test(i, j)){
							debug(i, j);
						}
					}
				}
			}
			cout << res << "\n";
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