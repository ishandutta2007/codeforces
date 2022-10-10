#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int w, h, n;
	cin >> w >> h >> n;
	multiset<int> hlen{w}, vlen{h};
	set<pair<int, int>> hori{{0, w}}, vert{{0, h}};
	for(int i = 0; i < n; ++ i){
		char type;
		int pos;
		cin >> type >> pos, pos;
		if(type == 'V'){
			auto it = -- hori.lower_bound({pos, numeric_limits<int>::max()});
			auto [l, r] = *it;
			hori.erase(it);
			hlen.erase(hlen.find(r - l));
			hori.insert({l, pos}), hori.insert({pos, r});
			hlen.insert(pos - l), hlen.insert(r - pos);
		}
		else{
			auto it = -- vert.lower_bound({pos, numeric_limits<int>::max()});
			auto [l, r] = *it;
			vert.erase(it);
			vlen.erase(vlen.find(r - l));
			vert.insert({l, pos}), vert.insert({pos, r});
			vlen.insert(pos - l), vlen.insert(r - pos);
		}
		cout << 1LL * *hlen.rbegin() * *vlen.rbegin() << "\n";
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