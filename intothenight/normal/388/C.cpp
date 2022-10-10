#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	array<int, 2> res{};
	vector<int> rem;
	for(auto i = 0; i < n; ++ i){
		int m;
		cin >> m;
		vector<int> a(m);
		for(auto j = 0; j < m; ++ j){
			cin >> a[j];
		}
		res[0] += accumulate(a.begin(), a.begin() + m / 2, 0);
		res[1] += accumulate(a.rbegin(), a.rbegin() + m / 2, 0);
		if(m & 1){
			rem.push_back(a[m / 2]);
		}
	}
	ranges::sort(rem | ranges::views::reverse);
	for(auto i = 0; i < (int)rem.size(); ++ i){
		res[i & 1] += rem[i];
	}
	cout << res[0] << " " << res[1] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////