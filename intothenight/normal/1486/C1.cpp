#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());


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
	#ifdef LOCAL
	int qcnt = 0;
	vector<int> res(n);
	iota(res.begin(), res.end(), 0);
	shuffle(res.begin(), res.end(), rng);
	for(auto i = 0; i < n; ++ i){
		cout << res[i] << " ";
	}
	cout << endl;
	int mxp = max_element(res.begin(), res.end()) - res.begin();
	cout << "mxp = " << mxp << endl;
	auto query = [&](int l, int r){
		++ qcnt;
		cout << "Q#" << qcnt << " " << l + 1 << " " << r << endl;
		if(qcnt > 40){
			cout << "TOO MANY Q" << endl;
			exit(0);
		}
		int pivot = max_element(res.begin() + l, res.begin() + r) - res.begin();
		int sp = pivot == l ? l + 1 : l;
		for(auto i = l; i < r; ++ i){
			if(i != pivot && res[i] > res[sp]){
				sp = i;
			}
		}
		cout << sp << endl;
		return sp;
	};
	auto answer = [&](int i){
		cout << "! " << i + 1 << endl;
		if(i != mxp){
			cout << "WA, wrong position" << endl;
			exit(0);
		}
		exit(0);
	};
	#else
	auto query = [&](int l, int r){
		cout << "? " << l + 1 << " " << r << endl;
		int i;
		cin >> i, -- i;
		return i;
	};
	auto answer = [&](int i){
		cout << "! " << i + 1 << endl;
		exit(0);
	};
	#endif
	int low = 0, high = n, p = query(0, n);
	while(high - low >= 4){
		int mid = low + (high - low >> 1);
		debug(p, low, mid, high);
		if(mid <= p){
			int q = query(mid, high);
			if(p == q){
				low = mid;
			}
			else{
				high = mid;
				p = query(low, high);
			}
		}
		else{ // p < mid
			int q = query(low, mid);
			if(p == q){
				high = mid;
			}
			else{
				low = mid;
				p = query(low, high);
			}
		}
	}
	if(high - low == 3){
		if(p == low || p == low + 1){
			if(query(low, low + 2) == p){
				low = p ^ low ^ low + 1, high = low + 1;
			}
			else{
				low = high - 1;
			}
		}
		else{
			if(query(low + 1, high) == p){
				low = high - 2, high = low + 1;
			}
			else{
				high = low + 1;
			}
		}
	}
	else if(high - low == 2){
		p == low ? ++ low : -- high;
	}
	answer(low);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////