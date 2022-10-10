#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	long long k;
	cin >> k;
	int x = 1;
	for(; ; ++ x){
		long long t = 1;
		for(auto rep = 0; rep < 10; ++ rep){
			t *= x;
		}
		if(t >= k){
			break;
		}
	}
	-- x;
	for(auto p = 0; ; ++ p){
		long long t = 1;
		for(auto rep = 0; rep < p; ++ rep){
			t *= x + 1;
		}
		for(auto rep = 0; rep < 10 - p; ++ rep){
			t *= x;
		}
		if(t >= k){
			string res("codeforces");
			for(auto i = 0; i < p; ++ i){
				cout << string(x + 1, res[i]);
			}
			for(auto i = p; i < 10; ++ i){
				cout << string(x, res[i]);
			}
			return 0;
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