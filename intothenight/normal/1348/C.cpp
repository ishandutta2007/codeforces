#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void SOLVE(){
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> cnt(26);
	for(auto c: s){
		++ cnt[c - 'a'];
	}
	int c = 0;
	while(!cnt[c]){
		++ c;
	}
	string rem;
	for(auto d = c + 1; d < 26; ++ d){
		rem.append(cnt[d], d + 'a');
	}
	if(cnt[c] == n){
		cout << string((n + k - 1) / k, c + 'a') << "\n";
	}
	else if(cnt[c] < k){
		cout << rem[k - cnt[c] - 1] << "\n";
	}
	else if(cnt[c] > k || !rem.empty() && rem.front() != rem.back()){
		string res(cnt[c] - (k - 1), c + 'a');
		res.append(rem);
		cout << res << "\n";
	}
	else{
		string res(1, c + 'a');
		int d = rem.front() - 'a';
		res.append((cnt[d] + k - 1) / k, d + 'a');
		cout << res << "\n";
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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