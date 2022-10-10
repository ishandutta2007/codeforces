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
	int n, m;
	cin >> n >> m;
	int h1 = (n - 1) / 2, h2 = (n - 2) / 2, cur = h1 * (h1 + 1) / 2 + h2 * (h2 + 1) / 2;
	if(m > cur){
		cout << -1;
		return 0;
	}
	vector<int> res(n);
	iota(res.begin(), res.end(), 1);
	const int mx = 1e9;
	int cnt = 0;
	while(cur > m){
		int x = res.back() - 1 >> 1;
		cur -= x;
		++ cnt;
		res.pop_back();
	}
	if(cur < m){
		-- cnt;
		int dif = m - cur;
		int x = res.empty() ? 0 : res.back();
		res.push_back(2 * x - 2 * dif + 1);
	}
	vector<int> temp{mx};
	if(!cnt){
		temp.pop_back();
	}
	for(int i = 1; i < cnt; ++ i){
		temp.push_back(temp.back() - res.back() - 1);
	}
	reverse(temp.begin(), temp.end());
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
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