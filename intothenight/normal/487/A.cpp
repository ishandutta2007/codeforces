#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	array<int, 3> h, a, d;
	for(auto i = 0; i < 3; ++ i){
		cin >> h[i] >> a[i] >> d[i];
	}
	int add = 0;
	while(a[0] <= d[1]){
		++ a[0];
		add += a[2];
	}
	int res = numeric_limits<int>::max();
	for(auto x = 0; x <= 10000; ++ x){
		for(auto y = 0; y <= 100; ++ y){
			for(auto z = 0; z <= 100; ++ z){
				if((d[0] + z) >= a[1] || (h[0] + x + a[1] - d[0] - z - 1) / (a[1] - d[0] - z) > (h[1] + a[0] + y - d[1] - 1) / (a[0] + y - d[1])){
					ctmin(res, x * h[2] + y * a[2] + z * d[2]);
				}
			}
		}
	}
	cout << res + add << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////