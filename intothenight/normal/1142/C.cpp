#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<array<int, 2>> temp(n);
	for(auto &[x, y]: temp){
		cin >> x >> y;
	}
	sort(temp.begin(), temp.end());
	vector<array<int, 2>> a;
	for(auto &[x, y]: temp){
		if(a.empty() || a.back()[0] != x){
			a.push_back({x, y});
		}
		else{
			a.back()[1] = y;
		}
	}
	n = int(a.size());
	vector<array<int, 2>> res;
	auto test = [&](auto p, auto q, auto r){
		long long d = q[0] - p[0];
		long long ad = q[1] - p[1] - 1LL * q[0] * q[0] + 1LL * p[0] * p[0];
		long long bd = d * (p[1] - 1LL * p[0] * p[0]) - p[0] * ad;
		return d * r[1] >= d * r[0] * r[0] + ad * r[0] + bd;
	};
	for(auto &p: a){
		while(int(res.size()) >= 2 && test(*next(res.rbegin()), *res.rbegin(), p)){
			res.pop_back();
		}
		res.push_back(p);
	}
	cout << int(res.size()) - 1;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////