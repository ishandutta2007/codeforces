#include <bits/stdc++.h>
using namespace std;

// Note: construction of an AC-automaton is offline.
// Adjacency_Type: array<int, X> or map<Char_Type, int> where X is the size of the alphabet
template<class Char_Type, class Adjacency_Type>
struct aho_corasic_automaton{
	// Begin States
	vector<int> len{0}, link{-1}, exit_link{-1};
	vector<bool> is_terminal{false};
	vector<Adjacency_Type> next{{}};
	// End States
	int new_state(){
		len.push_back(0);
		link.push_back(-1);
		exit_link.push_back(-1);
		is_terminal.push_back(false);
		next.push_back({});
		return (int)len.size() - 1;
	}
	aho_corasic_automaton(){ }
	aho_corasic_automaton(const vector<vector<Char_Type>> &patterns){
		for(auto s: patterns){
			int u = 0;
			for(auto c: s){
				if(!next[u][c]) next[u][c] = new_state(), len[next[u][c]] = len[u] + 1;
				u = next[u][c];
			}
			is_terminal[u] = true;
		}
		deque<int> dq{0};
		while(!dq.empty()){
			int u = dq.front(); dq.pop_front();
			if constexpr(is_same<Adjacency_Type, map<Char_Type, int>>::value){
				for(auto [c, v]: next[u]){
					link[v] = !~link[u] ? 0 : next[link[u]][c];
					exit_link[v] = is_terminal[link[v]] ? link[v] : exit_link[link[v]];
					dq.push_back(v); 
				}
			}
			else{
				for(auto c = 0; c < (int)next[u].size(); ++ c) if(next[u][c]){
					int v = next[u][c];
					link[v] = !~link[u] ? 0 : next[link[u]][c];
					exit_link[v] = is_terminal[link[v]] ? link[v] : exit_link[link[v]];
					dq.push_back(v); 
				}
			}
		}
	}
	int size() const{ // # of states
		return (int)len.size();
	}
};

template<class Char_Type, class Adjacency_Type>
struct trie{
	int n = 1; // # of active nodes(cnt != 0)
	vector<Adjacency_Type> next{{}};
	vector<int> cnt{1};
	trie(){ }
	trie(const vector<Adjacency_Type> &next, const vector<int> &cnt): n((int)next.size()), next(next), cnt(cnt){ }
	int extend(){
		next.emplace_back();
		cnt.push_back(0);
		return (int)next.size() - 1;
	}
	void insert(const vector<Char_Type> &a, int u = 0){
		if(!cnt[u] ++) ++ n;
		for(auto c: a){
			if(!next[u][c]) next[u][c] = extend();
			u = next[u][c];
			if(!cnt[u] ++) ++ n;
		}
	}
	void erase(const vector<Char_Type> &a, int u = 0){
		assert(cnt[u]);
		if(!-- cnt[u]) -- n;
		for(auto c: a){
			u = next[u][c];
			assert(u && cnt[u]);
			if(!-- cnt[u]) -- n;
		}
	}
	int size() const{ // # of states
		return (int)cnt.size();
	}
};


int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	trie<int, array<int, 26>> tr;
	for(auto i = 0; i < n; ++ i){
		string s;
		cin >> s;
		vector<int> a((int)s.size());
		for(auto i = 0; i < (int)s.size(); ++ i){
			a[i] = s[i] - 'a';
		}
		tr.insert(a);
	}
	int sz = (int)tr.size();
	vector<array<bool, 2>> dp(sz);
	for(auto u = sz - 1; u >= 0; -- u){
		dp[u] = {1, 1};
		bool flag = false;
		for(auto v: tr.next[u]){
			if(v){
				flag = true;
				if(dp[v][0]){
					dp[u][0] = 0;
				}
				if(dp[v][1]){
					dp[u][1] = 0;
				}
			}
		}
		if(!flag){
			dp[u][0] = 0;
		}
	}
	bool res;
	if(dp[0][0] && dp[0][1]){
		res = 1;
	}
	else if(!dp[0][0] && !dp[0][1]){
		res = 0;
	}
	else if(!dp[0][0] && dp[0][1]){
		res = 1;
	}
	else{
		res = ~k & 1;
	}
	res ? cout << "Second\n" : cout << "First\n";
	return 0;
}

/*
f(0): have losing strat (0: first, 1: second)
f(1): have winning strat (0: first, 1: secnod)

k th: f(1)
k-1 th: f(f(1))
...
1 st: f^k(1)
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////