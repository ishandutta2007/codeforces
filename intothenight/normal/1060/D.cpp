#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i] >> b[i];
	}
	sort(a.begin(), a.end()), sort(b.begin(), b.end());
	long long res = n;
	for(auto i = 0; i < n; ++ i){
		res += max(a[i], b[i]);
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