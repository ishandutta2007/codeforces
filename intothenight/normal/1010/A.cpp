#include <bits/stdc++.h>
using namespace std;
using namespace chrono;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> a(2 * n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i << 1];
	}
	for(auto i = 0; i < n; ++ i){
		int p = i ? (i - 1 << 1) + 1 : 2 * n - 1;
		cin >> a[p];
	}
	if(any_of(a.begin(), a.end(), [&](auto x){ return x == 1; })){
		cout << "-1\n";
		return 0;
	}
	cout << fixed << setprecision(15);
	auto test = [&](double f){
		for(auto x: a){
			if(m > (x - 1) * f){
				return false;
			}
			f -= (m + f) / x;
		}
		return true;
	};
	double low = 0, high = 1e18;
	auto START = high_resolution_clock::now();
	double TL = 0.5;
	while(duration<double>(high_resolution_clock::now() - START).count() < TL){
		double mid = (low + high) / 2;
		(test(mid) ? high : low) = mid;
	}
	cout << high << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////