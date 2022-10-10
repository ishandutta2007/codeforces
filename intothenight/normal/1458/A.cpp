#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<long long> a(n), b(m);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	long long g = 0;
	for(auto i = 1; i < n; ++ i){
		g = gcd(g, abs(a[i] - a[0]));
	}
	for(auto j = 0; j < m; ++ j){
		long long x;
		cin >> x;
		cout << gcd(a[0] + x, g) << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////