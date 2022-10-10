#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	long long k;
	string l, r;
	cin >> n >> k >> l >> r;
	long long res = 0, width = 1;
	for(auto i = 0; i < n; ++ i){
		width = min<long long>(numeric_limits<int>::max(), width * 2 - (l[i] == 'b') - (r[i] == 'a'));
		res += min(width, k);
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