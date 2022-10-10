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
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<vector<int>> pos(n);
	for(auto i = 0; i < n; ++ i){
		for(auto j = i + 1; j < n; ++ j){
			if(a[i] > a[j]){
				pos[i].push_back(j);
			}
		}
		sort(pos[i].begin(), pos[i].end(), [&](int i, int j){ return pair{a[i], i} > pair{a[j], j}; });
	}
	vector<array<int, 2>> res;
	for(auto i = 0; i < n; ++ i){
		for(auto j: pos[i]){
			res.push_back({i, j});
		}
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