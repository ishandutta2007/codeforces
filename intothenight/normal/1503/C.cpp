#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	long long res = 0;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0] >> a[i][1];
		res += a[i][1];
	}
	sort(a.begin(), a.end());
	int mx = a[0][0] + a[0][1];
	int pb = -1;
	for(auto [b, cost]: a){
		if(mx < b){
			res += b - mx;
		}
		ctmax(mx, b + cost);
		pb = b;
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