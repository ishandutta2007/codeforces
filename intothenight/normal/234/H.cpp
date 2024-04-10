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
	#ifdef LOCAL
	#else
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	#endif
	vector<pair<int, vector<int>>> a;
	int n;
	cin >> n;
	for(auto i = 0; i < n; ++ i){
		int t;
		cin >> t;
		if(a.empty() || a.back().first != t){
			a.push_back({t, {i}});
		}
		else{
			a.back().second.push_back(i);
		}
	}
	int m;
	cin >> m;
	vector<pair<int, vector<int>>> b;
	for(auto i = n; i < n + m; ++ i){
		int t;
		cin >> t;
		if(b.empty() || b.back().first != t){
			b.push_back({t, {i}});
		}
		else{
			b.back().second.push_back(i);
		}
	}
	debug(a, b);
	if((int)b.size() > (int)a.size()){
		swap(a, b);
	}
	int flag = false;
	if((int)a.size() == (int)b.size()){
		flag = true;
		if(a.back().first){
			swap(a, b);
		}
	}
	debug(flag);
	int j = a.back().first == b.back().first ? (int)a.size() - 1 : (int)a.size() - 2;

	for(auto i = (int)b.size() - 1; i >= 0 && j >= 0; -- i, -- j){
		a[j].second.insert(a[j].second.end(), b[i].second.begin(), b[i].second.end());
	}
	if(flag){
		a.insert(a.begin(), b.front());
	}
	vector<int> sz;
	for(auto &[t, v]: a){
		sz.push_back((int)v.size());
		for(auto x: v){
			cout << x + 1 << " ";
		}
	}
	cout << "\n";
	vector<int> res;
	int pref = 0;
	for(auto i = 0; i < (int)sz.size() - 1; ++ i){
		res.push_back(pref += sz[i]);
	}
	if(a.back().first){
		res.push_back(pref += sz.back());
	}
	cout << (int)res.size() << "\n";
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