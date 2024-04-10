#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	long long x, y;
	cin >> x >> y;
	if(gcd(x, y) == 1){
		vector<pair<long long, char>> res;
		while(x != 1 || y != 1){
			if(x > y){
				long long d = x / y;
				if(y == 1){
					-- d;
				}
				res.push_back({d, 'A'});
				x -= d * y;
			}
			else{
				long long d = y / x;
				if(x == 1){
					-- d;
				}
				res.push_back({d, 'B'});
				y -= d * x;
			}
		}
		for(auto [x, c]: res){
			cout << x << c;
		}
		cout << "\n";
	}
	else{
		cout << "Impossible\n";
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