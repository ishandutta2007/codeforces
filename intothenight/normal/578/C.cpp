#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	auto calc = [&](double d){
		double gmx = 0;
		double lmx = 0;
		double gmn = 0;
		double lmn = 0;
		for(auto x: a){
			ctmax(lmx += x + d, 0), ctmin(lmn += x + d, 0);
			ctmax(gmx, lmx), ctmin(gmn, lmn);
		}
		return max(gmx, -gmn);
	};
	double low = -1e9, high = 1e9;
	for(auto rep = 0; rep < 200; ++ rep){
		double mid1 = (2 * low + high) / 3, mid2 = (low + 2 * high) / 3;
		if(calc(mid1) > calc(mid2)){
			low = mid1;
		}
		else{
			high = mid2;
		}
	}
	cout << fixed << setprecision(15);
	cout << calc(low) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////