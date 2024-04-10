#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	string a, b;
	cin >> n >> a >> b;
	array<array<long long, 2>, 2> cnt{};
	for(auto i = 0; i < n; ++ i){
		++ cnt[a[i] & 1][b[i] & 1];
	}
	cout << cnt[0][1] * cnt[1][0] + cnt[1][0] * cnt[0][0] + cnt[0][0] * cnt[1][1] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////