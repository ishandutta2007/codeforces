#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	cout << (1LL * a[0] * k + a[1]) * (m / (k + 1)) + 1LL * a[0] * (m % (k + 1)) << "\n";
	return 0;
}

/*
7 7 4 7 7 4 7 7 4
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////