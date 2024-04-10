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
array<vector<int>, 2> manacher(const Str &s){
	int n = int(s.size());
	array<vector<int>, 2> p = {vector<int>(n + 1), vector<int>(n)};
	for(int z = 0; z < 2; ++ z){
		for(int i = 0 ,l = 0 , r = 0; i < n; ++ i){
			int t = r - i + !z;
			if(i < r) p[z][i] = min(t, p[z][l + t]);
			int L = i - p[z][i], R = i + p[z][i] - !z;
			while(L >= 1 && R + 1 < n && s[L - 1] == s[R + 1]) ++ p[z][i], -- L, ++ R;
			if(R > r) l = L, r = R;
		}
	}
	return p;
}
template<typename Str>
vector<int> z_function(const Str &s){
	int n = int(s.size());
	vector<int> z(n);
	for(int i = 1, l = 0, r = 1; i < n; ++ i){
		if(i < r) z[i] = min(r - i, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++ z[i];
		if(i + z[i] > r) l = i, r = i + z[i];
	}
	return z;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		string s;
		cin >> s;
		string t(s);
		reverse(t.begin(), t.end());
		int n = int(s.size());
		array<int, 4> res{0, 0, 0, 0}; // len, ttt, parity, i
		for(int ttt = 0; ttt < 2; ++ ttt){
			vector<int> z = z_function(s + t);
			auto p = manacher(s);
			for(int i = 1; i <= n; ++ i){
				if(n - i >= i){ // even
					if(z[n] + p[0][i] >= i){
						ctmax(res, {2 * i, ttt, 0, i});
					}
				}
				if(n - i >= i - 1){ // odd
					if(z[n] + p[1][i - 1] >= i - 1){
						ctmax(res, {2 * i - 1, ttt, 1, i});
					}
				}
			}
			swap(s, t);
		}
		if(res[1]){
			swap(s, t);
		}
		if(res[2]){
			string a = s.substr(0, res[3]);
			int sz = int(a.size());
			for(int i = sz - 2; i >= 0; -- i){
				a.push_back(a[i]);
			}
			cout << a << "\n";
		}
		else{
			string a = s.substr(0, res[3]);
			int sz = int(a.size());
			for(int i = sz - 1; i >= 0; -- i){
				a.push_back(a[i]);
			}
			cout << a << "\n";
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