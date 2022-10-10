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
	int tt;
	cin >> tt;
	while(tt --){
		int h, g;
		cin >> h >> g;
		vector<int> a((1 << h) - 1);
		copy_n(istream_iterator<int>(cin), (1 << h) - 1, a.begin());
		vector<int> res((1 << h) - (1 << g));
		auto check = [&](int i){
			while(i < (1 << g - 1) - 1){
				int l = 2 * i + 1, r = 2 * i + 2;
				if(a[l] > a[r]){
					i = l;
				}
				else{
					i = r;
				}
			}
			int l = 2 * i + 1, r = 2 * i + 2;
			return a[l] || a[r];
		};
		function<void(int)> process = [&](int i){
			int l = 2 * i + 1, r = 2 * i + 2;
			if(l >= (1 << h) - 1 || a[l] == a[r]){
				a[i] = 0;
			}
			else if(a[l] > a[r]){
				a[i] = a[l];
				process(l);
			}
			else{
				a[i] = a[r];
				process(r);
			}
		};
		int root = 0;
		for(int i = 0; i < (1 << h) - (1 << g); ++ i){
			while(!check(root)){
				++ root;
			}
			res[i] = root + 1;
			process(root);
		}
		cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
		copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
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