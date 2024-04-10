#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, d;
	cin >> n >> d;
	vector<int> refill(n);
	for(auto i = 1; i < n - 1; ++ i){
		cin >> refill[i];
	}
	vector<array<int, 2>> a(n);
	for(auto &[x, y]: a){
		cin >> x >> y;
	}
	auto bad = [&](int init)->bool{
		vector<int> opt(n);
		opt[0] = init;
		vector<int> done(n);
		while(true){
			int u = -1;
			for(auto v = 0; v < n; ++ v){
				if(!done[v] && (!~u || opt[u] < opt[v])){
					u = v;
				}
			}
			if(!~u || opt[u] < 0){
				break;
			}
			done[u] = true;
			for(auto v = 0; v < n; ++ v){
				if(!done[v] && opt[u] >= d * abs(a[u][0] - a[v][0]) + d * abs(a[u][1] - a[v][1])){
					opt[v] = max(opt[v], opt[u] - d * abs(a[u][0] - a[v][0]) - d * abs(a[u][1] - a[v][1]) + refill[v]);
					if(v == n - 1){
						return false;
					}
				}
			}
		}
		return true;
	};
	cout << *ranges::partition_point(ranges::iota_view(0, (int)1e8), bad) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////