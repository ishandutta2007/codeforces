#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<double> p(n);
	for(auto i = 0; i < n; ++ i){
		cin >> p[i], p[i] = (100 - p[i]) / 100;
	}
	if(n == 1){
		cout << "1\n";
		return 0;
	}
	vector<double> pe = p;
	double res = n;
	for(auto d = 0; d <= 1000000; ++ d){
		vector<double> pref(n + 1, 1), suff(n + 1, 1);
		for(auto i = 0; i < n; ++ i){
			pref[i + 1] = pref[i] * (1 - pe[i]);
		}
		for(auto i = n - 1; i >= 0; -- i){
			suff[i] = suff[i + 1] * (1 - pe[i]);
		}
		res += 1 - pref[n];
		pair<double, int> maxi{numeric_limits<double>::min(), -1};
		for(auto i = 0; i < n; ++ i){
			ctmax(maxi, pair{pref[i] * suff[i + 1] * (1 - pe[i] * p[i]), i});
		}
		int i = maxi.second;
		pe[i] *= p[i];
	}
	cout << fixed << setprecision(15);
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