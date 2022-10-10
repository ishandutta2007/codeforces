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

template<typename Str>
struct aho_corasic{
	typedef typename Str::value_type Char;
	struct node{
		int par, link = -1, elink = -1;
		Char cpar;
		map<Char, int> next, go;
		bool isleaf = false;
		int ind;
		node(int par = -1, Char pch = '$'): par(par), cpar(pch){ }
	};
	vector<node> state = vector<node>(1);
	void insert(int ind, const Str &s){
		int u = 0;
		for(auto &c: s){
			if(!state[u].next.count(c)){
				state[u].next[c] = int(state.size());
				state.emplace_back(u, c);
			}
			u = state[u].next[c];
		}
		state[u].isleaf = true;
		state[u].ind = ind;
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
		if(!state[u].go.count(c)){
			if(state[u].next.count(c)) state[u].go[c] = state[u].next[c];
			else state[u].go[c] = u ? go(get_link(u), c) : u;
		}
		return state[u].go[c];
	}
	void print(int u, Str s = ""){
		cout << "Node " << u << ": par = " << state[u].par << ", cpar = " << state[u].cpar << ", string: " << s << "\n";
		for(auto &[c, v]: state[u].next){
			cout << u << " => ";
			print(v, s + Str{c});
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;
	int n;
	cin >> s >> n;
	vector<pair<int, int>> a(n);
	aho_corasic<string> tr;
	for(int i = 0; i < n; i ++){
		string t;
		cin >> a[i].first >> t;
		a[i].second = int(t.size());
		tr.insert(i, t);
	}
	vector<vector<int>> match(n);
	for(int i = 0, u = 0; i < int(s.size()); i ++){
		u = tr.go(u, s[i]);
		for(int v = u; v; v = tr.get_elink(v)){
			if(tr.state[v].isleaf){
				match[tr.state[v].ind].push_back(i);
			}
		}
	}
	for(int i = 0; i < n; i ++){
		if(int(match[i].size()) < a[i].first){
			cout << "-1\n";
		}
		else{
			int res = 2e9;
			for(int j = 0; j + a[i].first <= int(match[i].size()); j ++){
				res = min(res, match[i][j + a[i].first - 1] - match[i][j]);
			}
			cout << res + a[i].second << "\n";
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