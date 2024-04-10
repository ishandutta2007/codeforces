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
	out << "{"; for(auto &x: arr) out << x << " ";
	return out << (arr.size() ? "\b" : "") << "}";
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
	int n, m;
	cin >> n >> m;
	vector<int> d(n);
	vector<array<int, 2>> a(n);
	long long tot_1 = 0;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0] >> a[i][1];
		d[i] = a[i][0] - a[i][1];
		tot_1 += a[i][1];
	}
	sort(d.begin(), d.end());
	vector<long long> pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] = pref[i] + d[i];
	}
	debug(d);
	debug(pref);
	vector<long long> res(n, tot_1);
	for(auto i = 0; i < n; ++ i){
		int p = lower_bound(d.begin(), d.end(), a[i][0] - a[i][1]) - d.begin();
		debug(i, p);
		res[i] += 1LL * (n - 1) * a[i][0] - a[i][1] + pref[p] + 1LL * p * (a[i][1] - a[i][0]);
	}
	debug(res);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		res[u] -= min(a[u][0] + a[v][1], a[u][1] + a[v][0]);
		res[v] -= min(a[u][0] + a[v][1], a[u][1] + a[v][0]);
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