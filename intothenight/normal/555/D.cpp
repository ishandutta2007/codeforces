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
	int n, qn;
	cin >> n >> qn;
	vector<int> x(n);
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> x[i];
		a[i] = {x[i], i};
	}
	sort(a.begin(), a.end());
	auto next = [&](int i, int len, bool dir)->tuple<int, int, bool>{
		if(dir){
			int right = upper_bound(a.begin() + i, a.end(), array{a[i][0] + len, numeric_limits<int>::max()}) - a.begin() - 1;
			assert(i <= right);
			int d = a[right][0] - a[i][0];
			return {right, len - d, !dir};
		}
		else{
			int left = lower_bound(a.begin(), a.begin() + i + 1, array{a[i][0] - len, numeric_limits<int>::min()}) - a.begin();
			int d = a[i][0] - a[left][0];
			return {left, len - d, !dir};
		}
	};
	for(auto qi = 0; qi < qn; ++ qi){
		int i, len;
		cin >> i >> len, -- i;
		i = lower_bound(a.begin(), a.end(), array{x[i], i}) - a.begin();
		bool dir = true;
		while(true){
			auto [ni, nlen, ndir] = next(i, len, dir);
			auto [nni, nnlen, nndir] = next(ni, nlen, ndir);
			if(len == nnlen){
				assert(i == ni && ni == nni);
				cout << a[i][1] + 1 << "\n";
				break;
			}
			if(i == nni){
				int d = len - nlen;
				assert(nlen - nnlen == d);
				if(len / d % 2){
					i = ni, len %= d, dir = !dir;
				}
				else{
					len %= d;
				}
			}
			else{
				i = nni, len = nnlen, dir = nndir;
			}
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