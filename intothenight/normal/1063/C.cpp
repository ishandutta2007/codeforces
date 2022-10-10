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
	auto query = [&](int x, int y){ // return 1 if white
		cout << x << " " << y << endl;
		string resp;
		cin >> resp;
		return resp == "white";
	};
	auto ans = [&](int x1, int y1, int x2, int y2){
		cout << x1 << " " << y1 << " " << x2 << " " << y2;
		exit(0);
	};
	int n;
	cin >> n;
	int a = query(0, 0), b = !a, c;
	-- n;
	if(!n){
		ans(10, 0, 0, 10);
	}
	c = query(0, 1e9);
	-- n;
	int low = 0, high = 1e9 + 1;
	while(n --){
		int mid = low + high >> 1;
		int resp = query(mid, 0);
		resp == a ? low = mid : high = mid;
	}
	if(c == a) ans(low + high >> 1, 0, low + high >> 1, 1);
	else ans(low + high >> 1, 0, 0, low + high >> 1);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////