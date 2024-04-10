#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, qq;
	cin >> n >> qq;
	while(qq --){
		int x, y;
		cin >> x >> y, -- x, -- y;
		if(x + y & 1){
			cout << (1LL * n * x + y >> 1) + 1 + (1LL * n * n + 1) / 2 << "\n";
		}
		else{
			cout << (1LL * n * x + y >> 1) + 1 << "\n";
		}
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