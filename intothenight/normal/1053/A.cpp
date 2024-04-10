#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, k;
	cin >> n >> m >> k;
	if(2LL * n * m % k){
		cout << "NO\n";
	}
	else if(gcd(2 * n, k) != 1){
		int g = gcd(2 * n, k), h = k / g;
		cout << "YES\n0 0\n" << 2 * n / g << " 0\n0 " << m / h << "\n";
	}
	else{
		int h = gcd(2 * m, k), g = k / h;
		cout << "YES\n0 0\n" << n / g << " 0\n0 " << 2 * m / h << "\n";
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