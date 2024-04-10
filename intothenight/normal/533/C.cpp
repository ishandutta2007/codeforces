#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int xp, yp, xv, yv;
	cin >> xp >> yp >> xv >> yv;
	for(auto i = 1; xv || yv; ++ i){
		if(xv){
			-- xv;
		}
		if(yv){
			-- yv;
		}
		if(abs(xp - xv) + abs(yp - yv) <= i){
			cout << "Polycarp\n";
			return 0;
		}
	}
	cout << "Vasiliy\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////