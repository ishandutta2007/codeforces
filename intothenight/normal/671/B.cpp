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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long long tot = accumulate(a.begin(), a.end(), 0LL);
	vector<int> b(n, tot / n);
	for(auto i = n - tot % n; i < n; ++ i){
		++ b[i];
	}
	long long rem = 0;
	for(auto i = 0; i < n; ++ i){
		rem += abs(a[i] - b[i]);
	}
	assert(~rem & 1);
	debug(rem, k);
	if(rem / 2 <= k){
		cout << b.back() - b.front() << "\n";
		return 0;
	}
	deque<array<int, 2>> dq;
	for(auto i = 0; i < n; ++ i){
		dq.push_back({a[i], 1});
	}
	debug(dq);
	debug("front");
	for(auto kk = k; kk; ){
		auto [x, xcnt] = dq.front();
		debug(x, xcnt);
		if(1LL * (dq[1][0] - x) * xcnt <= kk){
			kk -= 1LL * (dq[1][0] - x) * xcnt;
			x = dq[1][0], xcnt += dq[1][1];
			dq.pop_front(), dq.pop_front();
			dq.push_front({x, xcnt});
		}
		else{
			dq.pop_front();
			if(kk % xcnt){
				dq.push_front({x + kk / xcnt + 1, kk % xcnt});
			}
			dq.push_front({x + kk / xcnt, xcnt - kk % xcnt});
			kk = 0;
		}
		debug(dq);
	}
	sort(dq.begin(), dq.end());
	debug("back");
	for(auto kk = k; kk; ){
		auto [y, ycnt] = dq.back();
		debug(y, ycnt);
		if(1LL * (y - dq[(int)dq.size() - 2][0]) * ycnt <= kk){
			kk -= 1LL * (y - dq[(int)dq.size() - 2][0]) * ycnt;
			y = dq[(int)dq.size() - 2][0], ycnt += dq[(int)dq.size() - 2][1];
			dq.pop_back(), dq.pop_back();
			dq.push_back({y, ycnt});
		}
		else{
			dq.pop_back();
			if(kk % ycnt){
				dq.push_back({y - kk / ycnt - 1, kk % ycnt});
			}
			dq.push_back({y - kk / ycnt, ycnt - kk % ycnt});
			kk = 0;
		}
		debug(dq);
	}
	cout << dq.back()[0] - dq.front()[0] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////