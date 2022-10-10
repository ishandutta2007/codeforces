#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, k, r, c;
	cin >> n >> m >> k >> r >> c;
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	const int mod = 1e9 + 7;
	auto mul = [&](int x, int y)->int{
		return 1LL * x * y % mod;
	};
	auto power = [&](int b, long long e)->int{
		int res = 1;
		while(e){
			if(e & 1){
				res = mul(res, b);
			}
			b = mul(b, b);
			e >>= 1;
		}
		return res;
	};
	cout << power(k, 1LL * n * m - (tie(ax, ay) == tie(bx, by) ? 0 : 1LL * r * c)) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////