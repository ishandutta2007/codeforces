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
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	vector<vector<int>> res;
	while(true){
		int i = -1, j = -1;
		for(auto x = 0; x < n - 1; ++ x){
			int pos = find(a.begin(), a.end(), x) - a.begin();
			int npos = find(a.begin(), a.end(), x + 1) - a.begin();
			if(pos > npos){
				j = pos, i = npos;
				break;
			}
		}
		debug(a);
		debug(i, j);
		if(!~i){
			break;
		}
		int m = j;
		while(m > 0 && a[m - 1] == a[m] - 1){
			-- m;
		}
		debug(m);
		vector<int> cur;
		if(i){
			cur.push_back(i);
		}
		cur.push_back(m - i);
		cur.push_back(j - m + 1);
		if(j != n - 1){
			cur.push_back(n - 1 - j);
		}
		res.push_back(cur);
		vector<int> na;
		na.insert(na.end(), a.begin() + j + 1, a.end());
		na.insert(na.end(), a.begin() + m, a.begin() + j + 1);
		na.insert(na.end(), a.begin() + i, a.begin() + m);
		na.insert(na.end(), a.begin(), a.begin() + i);
		swap(a, na);
	}
	cout << (int)res.size() << "\n";
	for(auto &v: res){
		cout << (int)v.size() << " ";
		for(auto x: v){
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}

/*
 [...][(345)...][(12)][...]
       i          mj

6
6 5 4 3 2 1
1 2 6 5 4 3
3 4 1 2 6 5
6 5 1 2 3 4

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////