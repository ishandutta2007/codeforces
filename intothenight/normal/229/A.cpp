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
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	copy_n(istream_iterator<string>(cin), n, a.begin());
	vector<int> res(m);
	for(auto s: a){
		vector<int> cur(m, -1);
		deque<int> q;
		for(int i = 0; i < m; ++ i){
			if(s[i] == '1'){
				q.push_back(i);
				cur[i] = 0;
			}
		}
		if(q.empty()){
			cout << -1;
			return 0;
		}
		while(!q.empty()){
			int u = q.front();
			q.pop_front();
			int prev = (u - 1 + m) % m, next = (u + 1) % m;
			if(cur[prev] == -1){
				cur[prev] = cur[u] + 1;
				q.push_back(prev);
			}
			if(cur[next] == -1){
				cur[next] = cur[u] + 1;
				q.push_back(next);
			}
		}
		for(int i = 0; i < m; ++ i){
			res[i] += cur[i];
		}
	}
	cout << *min_element(res.begin(), res.end());
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////