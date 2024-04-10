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

template<typename Str, int lim = 32, typename Str::value_type PCH = '$'>
struct aho_corasic{
	typedef typename Str::value_type Char;
	struct node{
		int par, link = -1, elink = -1, depth = 0;
		Char cpar;
		vector<int> next, go;
		bool isleaf = false;
		node(int par = -1, Char pch = PCH): par(par), cpar(pch), next(lim, -1), go(lim, -1){ }
		long long val = 0;
		bool mark = false;
	};
	vector<node> state = vector<node>(1);
	int insert(const Str &s){
		int u = 0;
		for(auto &c: s){
			if(state[u].next[c] == -1){
				state[u].next[c] = int(state.size());
				state.emplace_back(u, c);
				state.back().depth = state[u].depth + 1;
			}
			u = state[u].next[c];
		}
		state[u].isleaf = true;
		return u;
	}
	int get_link(int u){
		if(state[u].link == -1){
			if(!u || !state[u].par) state[u].link = 0;
			else state[u].link = go(get_link(state[u].par), state[u].cpar);
		}
		return state[u].link;
	}
	int get_elink(int u){
		if(state[u].elink == -1){
			if(!u || !get_link(u)) state[u].elink = 0;
			else if(state[get_link(u)].isleaf) state[u].elink = get_link(u);
			else state[u].elink = get_elink(get_link(u));
		}
		return state[u].elink;
	}
	int go(int u, const Char &c){
		if(state[u].go[c] == -1){
			if(state[u].next[c] != -1) state[u].go[c] = state[u].next[c];
			else state[u].go[c] = u ? go(get_link(u), c) : u;
		}
		return state[u].go[c];
	}
	int go(const Str &s){
		int u = 0;
		for(auto &c: s) u = go(u, c);
		return u;
	}
	void print(int u, Str s = ""){
		cout << "Node " << u << ": par = " << state[u].par << ", cpar = " << state[u].cpar << ", string: " << s << "\n";
		for(int c = 0; c < lim; ++ c){
			if(state[u].next[c] != -1){
				cout << u << " => ";
				print(state[u].next[c], s + Str{c});
			}
		}
	}
};
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }


int solve_testcase(){
	int n;
	cin >> n;
	aho_corasic<string> ac;
	for(auto i = 0; i < n; ++ i){
		string s;
		cin >> s;
		for(auto &c: s){
			c -= 'a';
		}
		ac.insert(s);
	}
	int m = int(ac.state.size());
	vector<vector<int>> adj(m);
	for(auto u = 1; u < m; ++ u){
		int v = ac.get_link(u);
		if(v && ac.state[u].depth == ac.state[v].depth + 1){
			adj[u].push_back(v), adj[v].push_back(u);
			debug(u, v);
		}
	}
	vector<array<int, 2>> dp(m, {-1, -1});
	int res = 0;
	for(auto u = 1; u < m; ++ u){
		if(!~dp[u][0]){
			function<void(int, int)> dfs = [&](int u, int p){
				dp[u][0] = 0, dp[u][1] = 1;
				for(auto v: adj[u]){
					if(v ^ p){
						dfs(v, u);
						dp[u][0] += max(dp[v][0], dp[v][1]);
						dp[u][1] += dp[v][0];
					}
				}
			};
			dfs(u, u);
			res += max(dp[u][0], dp[u][1]);
		}
	}
	for(auto [x, y]: dp){
		debug(x, y);
	}
	cout << res << "\n";
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