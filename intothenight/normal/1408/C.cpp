#include <bits/stdc++.h>
using namespace std;

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
	cout << fixed << setprecision(15);
	auto __solve_tc = [&](int __tc_num){
		int n, l;
		cin >> n >> l;
		vector<int> a(n + 2);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i + 1];
		}
		a[n + 1] = l;
		vector<double> lt(n + 2), rt(n + 2);
		for(auto i = 1; i < n + 2; ++ i){
			lt[i] = lt[i - 1] + (a[i] - a[i - 1]) * 1.0 / i;
		}
		for(auto i = n; i >= 0; -- i){
			rt[i] = rt[i + 1] + (a[i + 1] - a[i]) * 1.0 / (n + 1 - i);
		}
		debug(lt);
		debug(rt);
		auto pred = [&](double t){ // does not meet
			int i = 0, j = n + 1;
			while(lt[i] < t){
				++ i;
			}
			while(rt[j] < t){
				-- j;
			}
			if(i - j >= 2){
				return false;
			}
			else if(i - j <= 0){
				return true;
			}
			else{
				return i * (t - lt[i - 1]) + (n + 1 - j) * (t - rt[j + 1]) < a[i] - a[j];
			}
		};
		double low = 0, high = min(lt[n + 1], rt[0]);
		for(auto rep = 0; rep < 200; ++ rep){
			double mid = (low + high) / 2;
			if(pred(mid)){
				low = mid;
			}
			else{
				high = mid;
			}
		}
		cout << high << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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