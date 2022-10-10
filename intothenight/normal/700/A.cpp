#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	int n, l, v1, v2, k;
	cin >> n >> l >> v1 >> v2 >> k;
	int g = (n + k - 1) / k;
	double len = 1.0 * l * (v1 + v2) / (v1 + v2 + 2LL * v1 * (g - 1));
	cout << len / v2 + (l - len) / v1 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////