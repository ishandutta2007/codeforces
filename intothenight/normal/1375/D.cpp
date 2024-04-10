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

int solve_testcase(){
	int n;
	cin >> n;
	vector<int> a(n);
	multiset<int> ms;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		ms.insert(a[i]);
	}
	auto get_mex = [&](){
		auto it = ms.begin();
		for(auto i = 0; ; ++ it){
			if(it == ms.end() || *it > i){
				return i;
			}
			if(*it == i){
				++ i;
			}
		}
	};
	vector<int> res;
	while(!is_sorted(a.begin(), a.end())){
		int i = get_mex();
		debug(a, i, ms);
		if(i == n || a[i] == i){
			int mind = -1;
			for(auto j = 0; j < n; ++ j){
				if(a[j] != j && (!~mind || a[mind] > a[j])){
					mind = j;
				}
			}
			ms.erase(ms.find(a[mind]));
			ms.insert(a[mind] = i);
			res.push_back(mind);
		}
		else{
			ms.erase(ms.find(a[i]));
			ms.insert(a[i] = i);
			res.push_back(i);
		}
	}
	cout << int(res.size()) << "\n";
	for(auto i: res){
		cout << i + 1 << " ";
	}
	cout << "\n";
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		solve_testcase();
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