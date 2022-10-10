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
	vector<int> t, mapto(n, -1), cnt(n + 1);
	for(int i = 0; i < n; ++ i){
		char c = s[i];
		if(c == '['){
			cnt[i + 1] = cnt[i] + 1;
		}
		else{
			cnt[i + 1] = cnt[i];
		}
		switch(c){
			case '(':
			t.push_back(i);
			break;
			case '[':
			t.push_back(i);
			break;
			case ')':
			if(t.empty() || s[t.back()] == '['){
				t.clear();
			}
			else{
				mapto[i] = t.back();
				mapto[t.back()] = i;
				t.pop_back();
			}
			break;
			case ']':
			if(t.empty() || s[t.back()] == '('){
				t.clear();
			}
			else{
				mapto[i] = t.back();
				mapto[t.back()] = i;
				t.pop_back();
			}
			break;
		}
	}
	pair<int, int> res;
	for(int i = 0; i < n; ){
		int j = i;
		while(j < n && mapto[j] != -1){
			++ j;
		}
		if(cnt[res.second] - cnt[res.first] < cnt[j] - cnt[i]){
			res = {i, j};
		}
		i = j + 1;
	}
	cout << cnt[res.second] - cnt[res.first] << "\n" << s.substr(res.first, res.second - res.first);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////