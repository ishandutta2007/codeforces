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
	vector<int> p{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	int tt;
	cin >> tt;
	while(tt --){
		int n;
		cin >> n;
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		vector<vector<int>> res(11);
		for(int i = 0; i < n; ++ i){
			for(int j = 0; j < 11; ++ j){
				if(a[i] % p[j] == 0){
					res[j].push_back(i);
					break;
				}
			}
		}
		int cnt = accumulate(res.begin(), res.end(), 0, [&](int x, const auto &y){ return x + !!int(y.size()); });
		cout << cnt << "\n";
		int ind = 0;
		vector<int> arr(n);
		for(auto &x: res){
			if(!x.empty()){
				++ ind;
				for(auto i: x){
					arr[i] = ind;
				}
			}
		}
		copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
		cout << "\n";
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