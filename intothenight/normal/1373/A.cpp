#include "bits/stdc++.h"
using namespace std;



int SOLVE(){
	int a, b, c;
	cin >> a >> b >> c;
	a < c ? cout << "1 " : cout << "-1 ";
	1LL * a * b > c ? cout << b << "\n" : cout << "-1\n";
	// a * x < c * ceil(x/b)
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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