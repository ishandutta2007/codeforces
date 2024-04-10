#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T, class Compare = less<>> using ordered_set = tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class U, class Compare = less<>> using ordered_map = tree<T, U, Compare, rb_tree_tag, tree_order_statistics_node_update>;

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
	vector<int> X, Y;
	for(auto &[x, y]: a){
		cin >> x >> y;
		X.push_back(x);
		Y.push_back(y);
	}
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	sort(Y.begin(), Y.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	int xn = (int)X.size(), yn = (int)Y.size();
	vector<vector<int>> occur(yn);
	for(auto &[x, y]: a){
		x = lower_bound(X.begin(), X.end(), x) - X.begin();
		y = lower_bound(Y.begin(), Y.end(), y) - Y.begin();
		occur[y].push_back(x);
	}
	ordered_set<int> os;
	long long res = 0;
	for(auto y = yn - 1; y >= 0; -- y){
		sort(occur[y].begin(), occur[y].end());
		for(auto x: occur[y]){
			os.insert(x);
		}
		debug(occur[y]);
		debug(os);
		for(auto i = 0; i < (int)occur[y].size(); ++ i){
			int ppos = i ? os.order_of_key(occur[y][i - 1]) : -1;
			int pos = os.order_of_key(occur[y][i]);
			debug(ppos, pos);
			res += 1LL * (pos - ppos) * ((int)os.size() - pos);
			debug(res);
		}
		debug(y, res);
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