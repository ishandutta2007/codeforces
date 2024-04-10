#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	int n, r;
	cin >> n >> r;
	vector<int> x(n);
	vector<double> y(n, r);
	for(auto i = 0; i < n; ++ i){
		cin >> x[i];
		for(auto j = 0; j < i; ++ j){
			if(abs(x[i] - x[j]) <= 2 * r){
				ctmax(y[i], y[j] + sqrt(4 * r * r - abs(x[i] - x[j]) * abs(x[i] - x[j])));
			}
		}
		cout << y[i] << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////