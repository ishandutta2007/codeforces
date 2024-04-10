#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	int n = int(s.size()), m = int(t.size());
	auto kill = [](){
		cout << "No";
		exit(0);
	};
	vector<vector<int>> occur(26);
	for(int j = 0; j < m; ++ j){
		char c = t[j];
		occur[c - 'a'].push_back(j);
		static int i = 0;
		while(i < n && s[i] != c){
			++ i;
		}
		if(i == n){
			kill();
		}
		++ i;
	}
	vector<int> pref(n), suff(n);
	for(int i = 0, p = 0; i < n; ++ i){
		int c = s[i] - 'a';
		if(p < m && t[p] - 'a' == c){
			pref[i] = ++ p;
		}
		else{
			if(occur[c].empty() || occur[c].front() >= p){
				kill();
			}
			else{
				pref[i] = *-- lower_bound(occur[c].begin(), occur[c].end(), p) + 1;
			}
		}
	}
	for(auto &s: occur){
		for(auto &x: s){
			x = m - 1 - x;
		}
	}
	for(int i = n - 1, p = 0; i >= 0; -- i){
		int c = s[i] - 'a';
		if(p < m && t[m - 1 - p] - 'a' == c){
			suff[i] = ++ p;
		}
		else{
			if(occur[c].empty() || occur[c].back() >= p){
				kill();
			}
			else{
				suff[i] = *-- lower_bound(occur[c].rbegin(), occur[c].rend(), p) + 1;
			}
		}
		if(pref[i] + suff[i] <= m){
			kill();
		}
	}
	cout << "Yes";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////