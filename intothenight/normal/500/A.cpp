#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, t;
	cin >> n >> t, -- t;
	vector<int> a(n - 1);
	for(auto i = 0; i < n - 1; ++ i){
		cin >> a[i];
	}
	int p = 0;
	while(p < n - 1){
		p += a[p];
		if(p == t){
			cout << "YES\n";
			return 0;
		}
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