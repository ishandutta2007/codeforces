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
	int n, x1, x2;
	cin >> n >> x1 >> x2;
	vector<int> c(n), req1(n), req2(n);
	for(auto i = 0; i < n; ++ i){
		cin >> c[i];
		req1[i] = (x1 + c[i] - 1) / c[i];
		req2[i] = (x2 + c[i] - 1) / c[i];
	}
	debug(req1);
	debug(req2);
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j){ return c[i] > c[j]; });
	for(auto t = 1; t < n; ++ t){
		if(req2[order[t]] <= t && req1[order[t - req2[order[t]]]] <= t + 1 - req2[order[t]]){
			cout << "Yes\n";
			vector<int> p, q;
			for(auto i = 0; i <= t - req2[order[t]]; ++ i){
				p.push_back(order[i]);
			}
			for(auto i = t - req2[order[t]] + 1; i <= t; ++ i){
				q.push_back(order[i]);
			}
			cout << (int)p.size() << " " << (int)q.size() << "\n";
			for(auto u: p){
				cout << u + 1 << " ";
			}
			cout << "\n";
			for(auto u: q){
				cout << u + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
		if(req1[order[t]] <= t && req2[order[t - req1[order[t]]]] <= t + 1 - req1[order[t]]){
			cout << "Yes\n";
			vector<int> p, q;
			for(auto i = 0; i <= t - req1[order[t]]; ++ i){
				q.push_back(order[i]);
			}
			for(auto i = t - req1[order[t]] + 1; i <= t; ++ i){
				p.push_back(order[i]);
			}
			cout << (int)p.size() << " " << (int)q.size() << "\n";
			for(auto u: p){
				cout << u + 1 << " ";
			}
			cout << "\n";
			for(auto u: q){
				cout << u + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////