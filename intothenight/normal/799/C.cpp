#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
ostream &operator<<(ostream &out, __int128_t x){
	if(!x) return out << 0;
	if(x < 0) out << "-", x = -x;
	array<int, 5> a{};
	int block = 29, it = 0;
	while(x) a[it ++] = x & (1 << block) - 1, x >>= block;
	while(it --) out << a[it];
	return out;
}
ostream &operator<<(ostream &out, __uint128_t x){
	if(!x) return out << 0;
	array<int, 5> a{};
	int block = 29, it = 0;
	while(x) a[it ++] = x & (1 << block) - 1, x >>= block;
	while(it --) out << a[it];
	return out;
}
ostream &operator<<(ostream &out, const _Bit_reference &bit){
	return out << bool(bit);
}
template<class T, class A, class C>
ostream &operator<<(ostream &out, priority_queue<T, A, C> pq){
	vector<T> a;
	while(!pq.empty()) a.push_back(pq.top()), pq.pop();
	return out << a;
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
	array<int, 2> money{};
	cin >> n >> money[0] >> money[1];
	array<vector<array<int, 2>>, 2> pool;
	array<int, 2> mxb{numeric_limits<int>::min() / 2, numeric_limits<int>::min() / 2};
	for(auto i = 0; i < n; ++ i){
		int b, p;
		char type;
		cin >> b >> p >> type;
		if(money[type - 'C'] >= p){
			pool[type - 'C'].push_back({p, b});
			ctmax(mxb[type - 'C'], b);
		}
	}
	debug2(pool);
	int res = 0;
	ctmax(res, mxb[0] + mxb[1]);
	for(auto t = 0; t < 2; ++ t){
		sort(pool[t].begin(), pool[t].end());
		vector<array<int, 2>> pref((int)pool[t].size() + 1, {numeric_limits<int>::min() / 2, numeric_limits<int>::min() / 2});
		for(auto i = 0; i < (int)pool[t].size(); ++ i){
			if(pref[i][0] < pool[t][i][1]){
				pref[i + 1] = {pool[t][i][1], pref[i][0]};
			}
			else if(pref[i][1] < pool[t][i][1]){
				pref[i + 1] = {pref[i][0], pool[t][i][1]};
			}
			else{
				pref[i + 1] = pref[i];
			}
		}
		debug(pref);
		for(auto i = (int)pool[t].size() - 1, j = 0; i >= 0; -- i){
			while(j < (int)pool[t].size() && pool[t][i][0] + pool[t][j][0] <= money[t]){
				++ j;
			}
			if(i < j && pool[t][i][1] == pref[j][0]){
				ctmax(res, pool[t][i][1] + pref[j][1]);
			}
			else{
				ctmax(res, pool[t][i][1] + pref[j][0]);
			}
		}
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