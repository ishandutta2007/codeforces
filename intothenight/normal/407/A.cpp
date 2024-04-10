#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int a, b;
	cin >> a >> b;
	for(auto x = 1; x < a; ++ x){
		int y = sqrt(a * a - x * x);
		while(x * x + (y + 1) * (y + 1) <= a * a){
			++ y;
		}
		if(x * x + y * y != a * a || x * b % a || y * b % a || a * y == b * x){
			continue;
		}
		cout << "YES\n";
		cout << -x << " " << y << "\n";
		cout << 0 << " " << 0 << "\n";
		cout << y * b / a << " " << x * b / a << "\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////