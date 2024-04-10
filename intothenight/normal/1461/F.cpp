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

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : p[u] = root(p[u]); } // O(alpha(n))
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	string allowed;
	cin >> allowed;
	sort(allowed.begin(), allowed.end());
	debug(allowed);
	auto report = [&](int l, int r, char c){
		if(l == r) return;
		cout << a[l];
		for(auto i = l + 1; i < r; ++ i){
			cout << c << a[i];
		}
	};
	auto solve_the_only_interesting_part_of_the_problem = [&](){
		auto solve = [&](int l, int r){
			debug("SOLVING", l, r);
			if(l == r) return;
			if(all_of(a.begin() + l, a.begin() + r, [&](int x){ return x == 1; })){
				report(l, r, '+');
				return;
			}
			if(r - l - count(a.begin() + l, a.begin() + r, 1) >= 19 || accumulate(a.begin() + l, a.begin() + r, 1LL, multiplies<>()) >= 2 * n){
				debug("HERE");
				int left = find_if(a.begin() + l, a.end(), [&](int x){ return x != 1; }) - a.begin();
				int right = a.rend() - find_if(a.rend() - r, a.rend(), [&](int x){ return x != 1; });
				debug(left, right);
				if(l != left){
					report(l, left, '+');
					cout << "+";
				}
				report(left, right, '*');
				if(right != r){
					cout << "+";
					report(right, r, '+');
				}
				return;
			}
			vector<array<int, 2>> blocks;
			for(auto i = l; i < r; ){
				while(i < r && a[i] == 1){
					++ i;
				}
				if(i < r){
					int j = i;
					while(j < r && a[j] > 1){
						++ j;
					}
					blocks.push_back({i, j});
					i = j;
				}
			}
			int m = (int)blocks.size();
			debug(blocks);
			vector<int> val(m, 1);
			for(auto t = 0; t < m; ++ t){
				for(auto i = blocks[t][0]; i < blocks[t][1]; ++ i){
					val[t] *= a[i];
				}
			}
			debug(val);
			vector<int> dp(m), prev(m, -1);
			dp[0] = val[0];
			for(auto i = 1; i < m; ++ i){
				dp[i] = dp[i - 1] * val[i];
			}
			for(auto i = 0; i < m; ++ i){
				int t = 1;
				for(auto j = i + 1; j < m; ++ j){
					t *= val[j];
					if(dp[j] < dp[i] + blocks[i + 1][0] - blocks[i][1] + t){
						prev[j] = i;
						dp[j] = dp[i] + blocks[i + 1][0] - blocks[i][1] + t;
					}
				}
			}
			debug(dp);
			debug(prev);
			string res(m - 1, '*');
			for(auto p = m - 1; ; ){
				p = prev[p];
				if(!~p){
					break;
				}
				res[p] = '+';
			}
			int left = blocks.front()[0], right = blocks.back()[1];
			if(l != left){
				report(l, left, '+');
				cout << "+";
			}
			for(auto i = 0; i < m - 1; ++ i){
				report(blocks[i][0], blocks[i][1], '*');
				cout << res[i];
				for(auto t = blocks[i][1]; t < blocks[i + 1][0]; ++ t){
					cout << a[t] << res[i];
				}
			}
			report(blocks.back()[0], blocks.back()[1], '*');
			if(right != r){
				cout << "+";
				report(right, r, '+');
			}
		};
		for(auto i = 0; i < n; ){
			while(i < n && !a[i]){
				cout << a[i];
				++ i;
				if(i == n){
					cout << "\n";
					return 0;
				}
				cout << "+";
			}
			if(i < n){
				int j = i;
				while(j < n && a[j]){
					++ j;
				}
				solve(i, j);
				if(j == n){
					cout << "\n";
					return 0;
				}
				cout << "+";
				i = j;
			}
		}
		return 0;
	};
	if((int)allowed.size() == 1){
		report(0, n, allowed[0]);
		cout << "\n";
	}
	else if((int)allowed.size() == 2){
		if(allowed == "*+"){
			solve_the_only_interesting_part_of_the_problem();
		}
		else if(allowed == "*-"){
			if(auto p = find(a.begin(), a.end(), 0); p != a.end()){
				if(p != a.begin()){
					report(0, p - a.begin(), '*');
					cout << '-';
					report(p - a.begin(), n, '*');
					cout << "\n";
				}
				else{
					report(0, n, '*');
					cout << "\n";
				}
			}
			else{
				report(0, n, '*');
				cout << "\n";
			}
		}
		else{
			report(0, n, '+');
			cout << "\n";
		}
	}
	else{
		solve_the_only_interesting_part_of_the_problem();
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