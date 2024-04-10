#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	vector<int> calc{0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
	int n;
	cin >> n;
	int g = 0;
	set<int> done;
	for(auto x = 2; x * x <= n; ++ x){
		if(!done.count(x)){
			int len = 0;
			for(auto y = x; y <= n; ){
				done.insert(y);
				++ len;
				if(__builtin_mul_overflow_p(y, x, 0)){
					break;
				}
				y *= x;
			}
			g ^= calc[len];
		}
	}
	g ^= n - (int)done.size() & 1;
	g ? cout << "Vasya\n" : cout << "Petya\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////