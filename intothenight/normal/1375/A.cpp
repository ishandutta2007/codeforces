#include "bits/stdc++.h"
using namespace std;



int solve_testcase(){
	int n;
	cin >> n;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		if((x < 0) ^ (i & 1)){
			x = -x;
		}
		cout << x << " ";
	}
	cout << "\n";
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