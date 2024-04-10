#include <bits/stdc++.h>
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
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<typename Head, typename... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "----DEBUG BEGIN----\n[" << #__VA_ARGS__ << "]:", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

template<typename Pred>
long long custom_binary_search(long long low, long long high, Pred p, const bool &is_left = true){
	assert(low < high);
	while(high - low > 1){
		auto mid = low + (high - low >> 1);
		(p(mid) == is_left ? low : high) = mid;
	}
	return is_left ? low : high;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<long long> h(n);
	for(auto i = 0; i < n; ++ i){
		cin >> h[i];
	}
	vector<int> q;
	long long last = h[0];
	for(auto i = 1; i < n; ++ i){
		while(!q.empty() && last + 1 <= h[i] - (i - q.back())){
			h[i] -= i - q.back();
			++ last;
			q.pop_back();
		}
		if(last + 2 <= h[i]){
			if(!q.empty()){
				q.back() += h[i] - (last + 1);
				h[i] = last + 1;
			}
			else{
				auto pred = [&](long long x){
					return last + x <= h[i] - x * i;
				};
				long long x = custom_binary_search(0, h[i] / i, pred);
				last += x, h[i] -= x * i;
				if(last + 2 <= h[i]){
					q.push_back(h[i] - (last + 1));
					h[i] = last + 1;
				}
			}
		}
		if(last == h[i]){
			q.push_back(i);
		}
		last = h[i];
		debug(last, q);
	}
	vector<long long> res(n, last);
	for(auto i = n - 2; i >= 0; -- i){
		if(!q.empty() && i + 1 == q.back()){
			q.pop_back();
			res[i] = res[i + 1];
		}
		else{
			res[i] = res[i + 1] - 1;
		}
	}
	for(auto x: res){
		cout << x << " ";
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