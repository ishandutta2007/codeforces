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
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	int low = -1, high = m;
	while(high - low > 1){
		int mid = low + high >> 1;
		auto test = [&](int x){
			int mx = 0;
			for(auto val: a){
				if(val >= mx){
					if(m - val + mx > x){
						mx = val;
					}
				}
				else{
					if(mx - val > x){
						return false;
					}
				}
			}
			return true;
		};
		test(mid) ? high = mid : low = mid;
	}
	cout << high;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////