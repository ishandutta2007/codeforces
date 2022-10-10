#include "bits/stdc++.h"
using namespace std;



int solve_testcase(){
	long long a, b, n, m;
	cin >> a >> b >> n >> m;
	if(m > min(a, b) || n + m > a + b){
		cout << "No\n";
	}
	else{
		cout << "Yes\n";
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