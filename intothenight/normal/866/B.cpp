#include <bits/stdc++.h>
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

// DEBUG BEGIN
#ifdef LOCAL
template<typename L, typename R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<typename Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<typename Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<typename... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<typename ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<typename T> ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<typename Head, typename... Tail>
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
	int n, s;
	cin >> n >> s;
	long long sum = 0, totcnt = 0;
	deque<array<int, 2>> a(n); // delta(A->B), cnt
	for(auto i = 0; i < n; ++ i){
		int x, p, q;
		cin >> x >> p >> q;
		totcnt += x, sum += 1LL * p * x;
		a[i] = {q - p, x};
	}
	long long ord = (totcnt + s - 1) / s;
	sort(a.begin(), a.end());
	long long cur_cnt = 0;
	for(auto i = 0; i < n && a[i][0] <= 0; ++ i){
		cur_cnt += a[i][1];
	}
	ord -= cur_cnt / s;
	long long acnt = cur_cnt / s * s;
	while(!a.empty()){
		if(a.front()[1] <= acnt){
			acnt -= a.front()[1];
			a.pop_front();
		}
		else{
			a.front()[1] -= acnt;
			break;
		}
	}
	cur_cnt = 0;
	n = int(a.size());
	for(auto i = n - 1; i >= 0 && a[i][0] > 0; -- i){
		cur_cnt += a[i][1];
	}
	ord -= cur_cnt / s;
	long long bcnt = cur_cnt / s * s;
	while(!a.empty()){
		if(a.back()[1] <= bcnt){
			sum += 1LL * a.back()[0] * a.back()[1];
			bcnt -= a.back()[1];
			a.pop_back();
		}
		else{
			sum += 1LL * a.back()[0] * bcnt;
			a.back()[1] -= bcnt;
			break;
		}
	}
	vector<int> t;
	for(auto [x, y]: a){
		t.insert(t.end(), y, x);
	}
	sort(t.begin(), t.end());
	debug(sum, t);
	long long res = 0, bsum = 0;
	for(auto acnt = int(t.size()), bcnt = 0; acnt >= 0; -- acnt, ++ bcnt){
		if(ord == (acnt + s - 1) / s + (bcnt + s - 1) / s){
			debug(acnt, bcnt, bsum);
			ctmax(res, bsum);
		}
		if(bcnt < int(t.size())){
			bsum += t[int(t.size()) - bcnt - 1];
		}
	}
	cout << sum + res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////