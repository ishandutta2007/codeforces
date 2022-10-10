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
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int>> cnt(26, vector<int>(n + 1));
	for(int i = 0; i < n; ++ i){
		for(int c = 0; c < 26; ++ c){
			if(c == s[i] - 'a'){
				cnt[c][i + 1] = cnt[c][i] + 1;
			}
			else{
				cnt[c][i + 1] = cnt[c][i];
			}
		}
	}
	long long res = 0;
	for(auto &s: cnt){
		long long x = s.back();
		ctmax(res, max<long long>(x, 1LL * x * (x - 1) / 2));
	}
	auto sum = [&](int c, int i, int j){
		return cnt[c][j] - cnt[c][i];
	};
	vector<vector<long long>> t(26, vector<long long>(26));
	for(int i = 0; i < 26; ++ i){
		for(int j = 0; j < 26; ++ j){
			if(i != j){
				for(int ind = 0; ind < n; ++ ind){
					if(s[ind] - 'a' == i){
						t[i][j] += sum(j, ind + 1, n);
					}
				}
			}
		}
	}
	for(auto &x: t){
		for(auto &y: x){
			ctmax(res, y);
		}
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