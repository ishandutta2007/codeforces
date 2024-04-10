#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n << 1);
	for(auto i = 0; i < n << 1; ++ i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long long res = 1LL * (a[n - 1] - a[0]) * (a[n * 2 - 1] - a[n]);
	for(auto i = 1; i < n; ++ i){
		ctmin(res, 1LL * (a.back() - a.front()) * (a[i + n - 1] - a[i]));
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