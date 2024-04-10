#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	long long k, x;
	cin >> n >> k >> x;
	vector<long long> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<array<long long, 2>> g;
	for(auto i = 0; i < n; ++ i){
		int j = i;
		while(j + 1 < n && a[j + 1] - a[j] <= x){
			++ j;
		}
		g.push_back({a[i], a[j]});
		i = j;
	}
	vector<long long> dif;
	for(auto i = 1; i < (int)g.size(); ++ i){
		dif.push_back(g[i][0] - g[i - 1][1]);
	}
	sort(dif.rbegin(), dif.rend());
	int res = (int)dif.size() + 1;
	while(!dif.empty()){
		auto cur = dif.back(); dif.pop_back();
		k -= (cur - 1) / x;
		if(k < 0){
			break;
		}
		-- res;
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////