#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int a, b;
	cin >> a >> b;
	if(a < b){
		cout << "-1\n";
	}
	else if(a == b){
		cout << a << "\n";
	}
	else{
		cout << fixed << setprecision(15);
		int x = (a - b) / b;
		if(x & 1){
			-- x;
		}
		int y = (a + b) / b;
		if(y & 1){
			-- y;
		}
		cout << min(1.0 * (a - b) / x, 1.0 * (a + b) / y) << "\n";
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