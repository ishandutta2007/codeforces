#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k, m;
	cin >> n >> k >> m;
	vector<array<int, 2>> a;
	int tot = n;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		if(a.empty() || a.back()[0] != x){
			a.push_back({x, 1});
		}
		else{
			++ a.back()[1];
		}
		if(a.back()[1] == k){
			a.pop_back();
			tot -= k;
		}
	}
	auto add = [&](auto a, auto b){
		for(auto x: b){
			if(a.empty() || a.back()[0] != x[0]){
				a.push_back(x);
			}
			else{
				a.back()[1] += x[1];
				if(a.back()[1] >= k){
					a.back()[1] -= k;
				}
				if(!a.back()[1]){
					a.pop_back();
				}
			}
		}
		return a;
	};
	auto b = add(a, a);
	if((int)a.size() < (int)b.size()){
		int tot2 = 0;
		for(auto [x, cnt]: b){
			tot2 += cnt;
		}
		cout << 1LL * tot * m - 1LL * (2 * tot - tot2) * (m - 1) << "\n";
	}
	else{
		vector<array<int, 2>> res;
		for(; m; m >>= 1, a = add(a, a)){
			if(m & 1){
				res = add(res, a);
			}
		}
		long long tot = 0;
		for(auto [x, cnt]: res){
			tot += cnt;
		}
		cout << tot << "\n";
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