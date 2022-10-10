#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	int m, n;
	cin >> m >> n;
	double res = 0;
	for(auto x = 1; x <= m; ++ x){
		res += x * (pow(1.0 * (m + 1 - x) / m, n) - pow(1.0 * (m - x) / m, n));
	}
	cout << m + 1 - res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////