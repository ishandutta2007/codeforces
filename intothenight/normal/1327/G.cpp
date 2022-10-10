#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename Str, int lim = 128>
struct aho_corasic{
	typedef typename Str::value_type Char;
	struct node{
		int par, link = -1, elink = -1;
		Char cpar;
		vector<int> next, go;
		bool isleaf = false;
		node(int par = -1, Char pch = '$'): par(par), cpar(pch), next(128, -1), go(128, -1){ }
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
	int go(int u, Char c){
		if(state[u].go[c] == -1){
			if(state[u].next[c] != -1) state[u].go[c] = state[u].next[c];
			else state[u].go[c] = u ? go(get_link(u), c) : u;
		}
		return state[u].go[c];
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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	aho_corasic<string> aut;
	int k;
	cin >> k;
	for(int i = 0; i < k; ++ i){
		string t;
		int x;
		cin >> t >> x;
		int u = aut.insert(t);
		aut.state[u].val += x;
	}
	int n = int(aut.state.size());
	function<long long(int)> process = [&](int u){
		if(aut.state[u].mark){
			return aut.state[u].val;
		}
		aut.state[u].mark = true;
		return aut.state[u].val += process(aut.get_elink(u));
	};
	for(int u = 0; u < n; ++ u){
		if(!aut.state[u].mark){
			process(u);
		}
	}
	const int mx = 14;
	string s;
	cin >> s;
	vector<vector<int>> masks(mx + 1);
	for(int mask = 0; mask < 1 << mx; ++ mask){
		masks[__builtin_popcount(mask)].push_back(mask);
	}
	const long long minf = numeric_limits<long long>::min() / 8;
	vector<vector<long long>> dp(n, vector<long long>(1 << mx, minf));
	dp[0][0] = 0;
	for(int i = 0; i < int(s.size()); ){
		static int cur_bit = 0;
		int j = i;
		while(j < int(s.size()) && s[j] != '?'){
			++ j;
		}
		static vector<vector<long long>> dp_next(n, vector<long long>(1 << mx));
		auto init_next = [&](){
			for(int i = 0; i < n; ++ i){
				for(int j = 0; j < 1 << mx; ++ j){
					dp_next[i][j] = minf;
				}
			}
		};
		init_next();
		for(int u = 0; u < n; ++ u){
			long long sum = 0;
			int v = u;
			for(int k = i; k < j; ++ k){
				v = aut.go(v, s[k]);
				sum += aut.state[v].val;
			}
			for(auto mask: masks[cur_bit]){
				if(dp[u][mask] != minf){
					ctmax(dp_next[v][mask], dp[u][mask] + sum);
				}
			}
		}
		swap(dp, dp_next);
		if(j < int(s.size())){
			init_next();
			for(auto mask: masks[cur_bit]){
				for(int bit = 0; bit < mx; ++ bit){
					if(!(mask & 1 << bit)){
						int vmask = mask | 1 << bit;
						for(int u = 0; u < n; ++ u){
							if(dp[u][mask] != minf){
								int v = aut.go(u, 'a' + bit);
								ctmax(dp_next[v][vmask], dp[u][mask] + aut.state[v].val);
							}
						}
					}
				}	
			}
			swap(dp, dp_next);
			++ cur_bit;
		}
		i = j + 1;
	}
	long long res = minf;
	for(int u = 0; u < n; ++ u){
		ctmax(res, *max_element(dp[u].begin(), dp[u].end()));
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////