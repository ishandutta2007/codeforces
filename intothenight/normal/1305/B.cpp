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
	string s;
	cin >> s;
	int n = int(s.size());
	if(n == 1){
		cout << "0";
		return 0;
	}
	vector<int> cnt(n), rev(n);
	for(int i = 0; i < n; ++ i){
		if(s[i] == '('){
			cnt[i] = i ? cnt[i - 1] + 1 : 1;
		}
		else{
			cnt[i] = i ? cnt[i - 1] : 0;
		}
	}
	for(int i = n - 1; i >= 0; -- i){
		if(s[i] == ')'){
			rev[i] = i != n - 1 ? rev[i + 1] + 1 : 1;
		}
		else{
			rev[i] = i != n - 1 ? rev[i + 1] : 0;
		}
	}
	int res = -1;
	for(int i = 1; i < n; ++ i){
		if(res == -1 || min(cnt[res - 1], rev[res]) < min(cnt[i - 1], rev[i])){
			res = i;
		}
	}
	int x = min(cnt[res - 1], rev[res]);
	if(x) cout << "1\n" << 2 * x << "\n";
	else cout << "0";
	int t = x;
	for(int i = 0; t; ++ i){
		if(s[i] == '('){
			-- t;
			cout << i + 1 << " ";
		}
	}
	t = x;
	vector<int> temp;
	for(int i = n - 1; t; -- i){
		if(s[i] == ')'){
			-- t;
			temp.push_back(i + 1);
		}
	}
	reverse(temp.begin(), temp.end());
	copy(temp.begin(), temp.end(), ostream_iterator<int>(cout, " "));
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////