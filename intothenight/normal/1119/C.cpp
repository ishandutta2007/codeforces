#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> r(n), c(m);
	for(auto rep = 0; rep < 2; ++ rep){
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				int x;
				cin >> x;
				r[i] ^= x, c[j] ^= x;
			}
		}
	}
	accumulate(r.begin(), r.end(), accumulate(c.begin(), c.end(), 0)) == 0 ? cout << "YES\n" : cout << "NO\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////