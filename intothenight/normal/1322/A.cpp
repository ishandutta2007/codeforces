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



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	string s;
	cin >> n >> s;
	int cnt0 = 0, cnt1 = 0;
	for(auto c: s){
		if(c == '('){
			++ cnt0;
		}
		else{
			++ cnt1;
		}
	}
	if(cnt0 != cnt1){
		cout << -1;
		return 0;
	}
	int res = 0;
	for(int i = 0, sum = 0; i < n; ++ i){
		sum += (s[i] == '(') - (s[i] == ')');
		if(sum < 0){
			++ res;
			while(sum < 0){
				++ i, ++ res;
				sum += (s[i] == '(') - (s[i] == ')');
			}
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