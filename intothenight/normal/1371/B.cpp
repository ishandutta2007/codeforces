#include "bits/stdc++.h"
using namespace std;



int solve_testcase(){
	int n, r;
	cin >> n >> r;
	if(r < n){
		cout << 1LL * r * (r + 1) / 2 << "\n";
	}
	else{
		cout << 1LL * (n - 1) * n / 2 + 1 << "\n";
	}
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