#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<class T> T ctmax(T &x, const T &y){ return x = max(x, y);}
template<class T> T ctmin(T &x, const T &y){ return x = min(x, y);}
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


template<typename Str>
vector<int> prefix_function(const Str &s){
	int n = int(s.size());
	vector<int> p(n);
	for(int i = 1; i < n; ++ i){
		int j = p[i - 1];
		while(j > 0 && s[i] != s[j]) j = p[j - 1];
		if(s[i] == s[j]) ++ j;
		p[i] = j;
	}
	return p;
}
template<typename Str, int lim = 128>
pair<vector<int>, vector<vector<int>>> prefix_automaton(const Str &s){
	vector<int> p = prefix_function(s);
	int n = int(s.size());
	vector<vector<int>> aut(n, vector<int>(lim + 1));
	for(int i = 0; i < n; ++ i) for(int c = 0; c <= lim; ++ c){
		if(i > 0 && c != s[i]) aut[i][c] = aut[p[i - 1]][c];
		else aut[i][c] = i + (c == s[i]);
	}
	return {p, aut};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	int n = int(s.size()), m = int(t.size());
	auto [p, aut] = prefix_automaton(t);
	vector<vector<int>> d(n + 1, vector<int>(m, numeric_limits<int>::min()));// d[i][j]: ans for first i of s, matched with first j of t
	d[0][0] = 0;
	for(int i = 0; i < n; ++ i){
		for(int j = 0; j < m; ++ j){
			if(s[i] == '?'){
				for(int c = 'a'; c <= 'z'; ++ c){
					if(aut[j][c] == m) ctmax(d[i + 1][p[m - 1]], d[i][j] + 1);
					else ctmax(d[i + 1][aut[j][c]], d[i][j]);
				}
			}
			else{
				if(aut[j][s[i]] == m) ctmax(d[i + 1][p[m - 1]], d[i][j] + 1);
				else ctmax(d[i + 1][aut[j][s[i]]], d[i][j]);
			}
		}
	}
	cout << *max_element(d[n].begin(), d[n].end());
	return 0;
}
 
/*
 
*/
 
////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////