#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		int n, m;
		string s;
		cin >> n >> m >> s;
		vector<int> p(m);
		for(auto &x: p){
			cin >> x;
		}
		p.push_back(n);
		vector<vector<int>> SUM(n + 1, vector<int>(26));
		for(int i = 0; i < n; ++ i){
			for(int c = 0; c < 26; ++ c){
				if(c == s[i] - 'a'){
					SUM[i + 1][c] = SUM[i][c] + 1;
				}
				else{
					SUM[i + 1][c] = SUM[i][c];
				}
			}
		}
		vector<long long> res(26);
		for(auto r: p){
			for(int c = 0; c < 26; ++ c){
				res[c] += SUM[r][c];
			}
		}
		for(auto x: res){
			cout << x << " ";
		}
		cout << "\n";
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