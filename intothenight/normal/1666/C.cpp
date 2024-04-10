#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	array<array<int, 2>, 3> a;
	array<int, 2> p{};
	for(auto i = 0; i < 3; ++ i){
		for(auto j = 0; j < 2; ++ j){
			cin >> a[i][j];
			p[j] ^= a[i][j];
		}
	}
	for(auto j = 0; j < 2; ++ j){
		p[j] ^= min({a[0][j], a[1][j], a[2][j]}) ^ max({a[0][j], a[1][j], a[2][j]});
	}
	cout << "6\n";
	for(auto i = 0; i < 3; ++ i){
		auto q = a[i];
		cout << p[0] << " " << p[1] << " " << p[0] << " " << q[1] << "\n";
		cout << p[0] << " " << q[1] << " " << q[0] << " " << q[1] << "\n";
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