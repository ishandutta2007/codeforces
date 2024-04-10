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
	int n, a, b, k; // len, # of ships, len of ship, # of shots
	string s;
	cin >> n >> a >> b >> k >> s;
	vector<array<int, 3>> ndiv, rem;
	int tot = 0;
	for(auto i = 0; i < n; ){
		while(i < n && s[i] == '1'){
			++ i;
		}
		if(i < n){
			int j = i;
			while(j < n && s[j] == '0'){
				++ j;
			}
			if((j - i) % b){
				ndiv.push_back({(j - i) / b, i, j});
				tot += (j - i) / b;
			}
			else{
				rem.push_back({(j - i) / b, i, j});
				tot += (j - i) / b;
			}
			i = j;
		}
	}
	sort(ndiv.begin(), ndiv.end());
	vector<int> res;
	a = tot - a + 1;
	for(auto [cnt, i, j]: ndiv){
		if(cnt < a){
			a -= cnt;
			while((i += b - 1) < j){
				res.push_back(i);
				++ i;
			}
		}
		else{
			if(cnt == a){
				while((i += b - 1) < j){
					res.push_back(i);
					++ i;
				}
			}
			else{
				while(a && (i += b - 1) < j){
					res.push_back(i);
					++ i, -- a;
				}
			}
			goto DONE;
		}
	}
	for(auto [cnt, i, j]: rem){
		if(cnt < a){
			a -= cnt;
			while((i += b - 1) < j){
				res.push_back(i);
				++ i;
			}
		}
		else{
			while(a && (i += b - 1) < j){
				res.push_back(i);
				++ i, -- a;
			}
			goto DONE;
		}
	}
	DONE:;
	cout << (int)res.size() << "\n";
	for(auto i: res){
		cout << i + 1 << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////