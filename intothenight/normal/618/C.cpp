#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 3>> a(n);
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < 2; ++ j){
			cin >> a[i][j];
		}
		a[i][2] = i;
	}
	sort(a.begin(), a.end());
	int t = 2;
	while(1LL * (a[0][0] - a[1][0]) * (a[t][1] - a[0][1]) == 1LL * (a[0][1] - a[1][1]) * (a[t][0] - a[0][0])){
		++ t;
	}
	cout << a[0][2] + 1 << " " << a[1][2] + 1 << " " << a[t][2] + 1 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////