#include "bits/stdc++.h"
using namespace std;



int solve_testcase(){
	int n;
	cin >> n;
	int res = 1;
	for(auto low = 1, d = 1; low <= n; low = d + 1){
		d = n / (n / low);
		if(d != n && n % d == 0){
			res = d;
		}
	}
	cout << res << " " << n - res << "\n";
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		solve_testcase();
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