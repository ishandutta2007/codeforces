#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0] >> a[i][1];
	}
	double res = numeric_limits<double>::max();
	for(auto j = 0; j < n; ++ j){
		int i = (j - 1 + n) % n, k = (j + 1) % n;
		array<int, 2> y{a[j][0] - a[i][0], a[j][1] - a[i][1]}, x{a[k][0] - a[i][0], a[k][1] - a[i][1]};
		ctmin(res, abs((1LL * x[0] * y[1] - 1LL * y[0] * x[1]) / hypot(x[0], x[1])) / 2);
	}
	cout << fixed << setprecision(15) << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////