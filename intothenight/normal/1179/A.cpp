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
	int n, q;
	cin >> n >> q;
	deque<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	vector<pair<int, int>> res(n);
	for(int i = 0; i < n; ++ i){
		res[i] = {a[0], a[1]};
		int p = a[0], q = a[1];
		if(p < q){
			swap(p, q);
		}
		a.pop_front(), a.pop_front();
		a.push_front(p), a.push_back(q);
	}
	while(q --){
		long long m;
		cin >> m, -- m;
		if(m < n){
			cout << res[m].first << " " << res[m].second << "\n";
		}
		else{
			m += n - 2;
			cout << a[0] << " " << a[m % (n - 1) + 1] << "\n";
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