#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> depth(n), cnt(n);
	cnt[0] ^= 1;
	for(auto u = 1; u < n; ++ u){
		int p;
		cin >> p, -- p;
		depth[u] = depth[p] + 1;
		cnt[depth[u]] ^= 1;
	}
	cout << accumulate(cnt.begin(), cnt.end(), 0) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////