#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	long long x, y, m;
	cin >> x >> y >> m;
	if(x < y){
		swap(x, y);
	}
	if(x >= m){
		cout << "0\n";
		return 0;
	}
	if(x <= 0){
		cout << "-1\n";
		return 0;
	}
	long long res = 0;
	if(y < 0){
		res += -y / x;
		y += -y / x * x;
	}
	while(m > x){
		++ res;
		tie(x, y) = pair{x, x + y};
		if(x < y){
			swap(x, y);
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////