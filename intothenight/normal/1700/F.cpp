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
	vector<vector<int>> a(2, vector<int>(n));
	for(auto &x: a | ranges::views::join){
		cin >> x;
	}
	for(auto &x: a | ranges::views::join){
		int y;
		cin >> y;
		x -= y;
	}
	long long res = 0;
	array<int, 2> rem{};
	for(auto j = 0; j < n; ++ j){
		res += abs(rem[0]) + abs(rem[1]);
		rem[0] += a[0][j];
		rem[1] += a[1][j];
		if(rem[0] > 0 && rem[1] < 0){
			int delta = min(rem[0], -rem[1]);
			res += delta;
			rem[0] -= delta;
			rem[1] += delta;
		}
		else if(rem[0] < 0 && rem[1] > 0){
			int delta = min(-rem[0], rem[1]);
			res += delta;
			rem[0] += delta;
			rem[1] -= delta;
		}
	}
	if(rem[0] || rem[1]){
		cout << "-1\n";
		return 0;
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