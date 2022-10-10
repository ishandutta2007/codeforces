#include "bits/stdc++.h"
using namespace std;



int SOLVE(){
	int a, b, n;
	cin >> a >> b >> n;
	for(auto i = 0; ; ++ i){
		if(a < b){
			swap(a, b);
		}
		if(a > n){
			cout << i << "\n";
			return 0;
		}
		b += a;
	}
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