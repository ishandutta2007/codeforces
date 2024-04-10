#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		string s;
		cin >> s;
		int cnt = 0;
		int l = -1, r = -1;
		for(int i = 0; i < int(s.size()); ++ i){
			cnt += s[i] - '0';
			if(l == -1 && s[i] == '1') l = i;
			if(s[i] == '1') r = i;
		}
		if(r == -1) cout << "0\n";
		else cout << r - l + 1 - cnt << "\n";
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