#include "bits/stdc++.h"
using namespace std;

// DEBUG BEGIN
template<typename L, typename R>
ostream &operator<<(ostream &out, pair<L, R> p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<typename Tuple, size_t ...Is>
void print_tuple(ostream &out, Tuple t, index_sequence<Is...>){
	((out << (Is ? ", " : "") << get<Is>(t)), ...);
}
template<typename ...Args>
ostream &operator<<(ostream &out, tuple<Args...> t){
	out << "(", print_tuple(out, t, index_sequence_for<Args...>{}); return out << ")";
}
template<typename ...Args, template<typename...> typename T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, T<Args...> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S>
ostream &operator<<(ostream &out, bitset<S> b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	vector<pair<long long, int>> a(3);
	for(auto i = 0; i < 3; ++ i){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	cout << "First" << endl;
	int prev = -1;
	auto query = [&](long long x){
		cout << x << endl;
		int pos;
		cin >> pos;
		if(!pos || !~pos){
			exit(0);
		}
		-- pos;
		prev = pos;
		for(auto i = 0; i < 3; ++ i){
			if(a[i].second == pos){
				a[i].first += x;
				sort(a.begin(), a.end());
				return;
			}
		}
	};
	while(1){
		long long p = a[1].first - a[0].first, q = a[2].first - a[1].first;
		if(p == q){
			query(p), query(5 * p);
		}
		else if(!~prev){
			query(p + q);
		}
		else{
			query(p + 2 * q);
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