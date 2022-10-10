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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](){
		int n, x, y;
		cin >> n >> x >> y, y -= x;
		vector<vector<int>> pos(n + 1);
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
			pos[a[i]].push_back(i);
		}
		int extra = 0;
		while(!pos[extra].empty()){
			++ extra;
		}
		vector<int> res(n, -1);
		set<pair<int, int>, greater<>> s;
		for(auto c = 0; c <= n; ++ c){
			if(!pos[c].empty()){
				s.insert({int(pos[c].size()), c});
			}
		}
		for(auto rep = 0; rep < x; ++ rep){
			auto [ignore, c] = *s.begin(); s.erase(s.begin());
			res[pos[c].back()] = c; pos[c].pop_back();
			s.insert({int(pos[c].size()), c});
		}
		vector<int> t;
		for(auto it = s.rbegin(); it != s.rend(); ++ it){
			for(auto i: pos[it->second]){
				t.push_back(i);
			}
		}
		debug(res);
		debug(t);
		for(auto rep = 0, i = 0; rep < y; ++ rep){
			while(i < int(t.size()) && a[t[i]] == a[t[(i + int(t.size()) / 2) % int(t.size())]]){
				++ i;
			}
			if(i == int(t.size())){
				cout << "NO\n";
				return 0;
			}
			debug(i);
			res[t[i]] = a[t[(i + int(t.size()) / 2) % int(t.size())]];
			++ i;
		}
		cout << "YES\n";
		for(auto c: res){
			~c ? cout << c + 1 << " " : cout << extra + 1 << " ";
		}
		cout << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_it = 0; __tc_it < __tc_cnt; ++ __tc_it){
		__solve_tc();
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