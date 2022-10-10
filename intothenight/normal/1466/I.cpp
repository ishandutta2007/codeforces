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
	int n, B;
	cin >> n >> B;
	auto query = [&](int i, string x){ // a[i] > x ?
		cout << i << " " << x.substr(0, B) << endl;
		string resp;
		return cin >> resp, resp[0] == 'y';
	};
	string low(450, '1'); // low + 2^(len - 1 - b) - eps
	-- low[0];
	deque<int> dq(n);
	iota(dq.begin(), dq.end(), 1);
	for(auto b = 0; b - (int)dq.size() + 1 < B; ){
		debug(b, low);
		debug(dq);
		int ind = dq.back();
		if(query(ind, low)){
			while(low[b] & 1){
				-- b;
				dq.pop_front();
			}
			++ low[b];
		}
		else{
			-- low[++ b];
			dq.pop_back();
			dq.push_front(ind);
		}
	}
	cout << "0 " << low.substr(0, B) << "\n";
	return 0;
}

/*
4 2
[cur_alive]: {1, 2, 3, 4}
1 01
yes
[cur_alive]: {1, 2, 3, 4}
1 11
no
[cur_alive]: {2, 3, 4, 1}
2 10
no
[cur_alive]: {3, 4, 1, 2}
3 10
no
[cur_alive]: {4, 1, 2, 3}
4 10
no
[cur_alive]: {1, 2, 3, 4}
1 10
yes
[cur_alive]: {1, 2, 3, 4}
1 10
yes
[cur_alive]: {1, 2, 3}
1 10
yes
[cur_alive]: {1, 2}
1 10
yes
[cur_alive]: {1}
1 11
no
0 11
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////