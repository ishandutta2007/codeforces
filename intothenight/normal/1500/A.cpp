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
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0], a[i][1] = i;
	}
	sort(a.begin(), a.end());
	auto answer = [&](int i, int j, int k, int l){
		cout << "YES\n";
		cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << "\n";
		exit(0);
	};
	#ifdef LOCAL
	const int mx = 5e6;
	#else
	const int mx = 5e6;
	#endif
	vector<array<int, 2>> rem(mx, {-1, -1});
	for(auto i = 2; i < n; ++ i){
		if(~rem[a[i][0] - a[i - 1][0]][0]){
			auto [x, y] = rem[a[i][0] - a[i - 1][0]];
			answer(a[i][1], y, a[i - 1][1], x);
		}
		rem[a[i - 1][0] - a[i - 2][0]] = {a[i - 1][1], a[i - 2][1]};
	}
	vector<pair<int, array<int, 2>>> rem2;
	vector<pair<int, int>> occur;
	for(auto i = 0; i < n; ++ i){
		for(auto j = i + 1; j < n; ++ j){
			rem2.push_back({a[i][0] + a[j][0], {i, j}});
			occur.push_back({a[i][0] + a[j][0], i});
			occur.push_back({a[i][0] + a[j][0], j});
		}
	}
	sort(rem2.begin(), rem2.end());
	sort(occur.begin(), occur.end());
	auto count = [&](int x, int i){
		auto [l, r] = equal_range(occur.begin(), occur.end(), pair{x, i});
		return int(r - l);
	};
	for(auto l = 0; l < (int)rem2.size(); ){
		int r = l;
		while(r < (int)rem2.size() && rem2[l].first == rem2[r].first){
			++ r;
		}
		int x = rem2[l].first;
		for(auto t = l; t < r; ++ t){
			auto [i, j] = rem2[t].second;
			if(count(x, i) + count(x, j) - 1 < r - l){
				for(auto tt = l; tt < r; ++ tt){
					auto [k, l] = rem2[tt].second;
					if(i != k && i != l && j != k && j != l){
						answer(a[i][1], a[j][1], a[k][1], a[l][1]);
					}
				}
				assert(false);
			}
		}
		debug(l, r);
		l = r;
	}
	cout << "NO\n";
	return 0;
}

/*
7
(1) 7 [6] (10) 7 [5] 7 
NO
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////