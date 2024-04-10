#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for(auto i = 0; i < m; ++ i){
		cin >> a[i] >> a[i];
	}
	sort(a.rbegin(), a.rend());
	int x = 0;
	while(x + 2 <= m && (x + 2) * (x + 1) / 2 + (x + 2) / 2 <= n){
		x += 2;
	}
	long long res = accumulate(a.begin(), a.begin() + x, 0LL);
	x = 1;
	while(x + 2 <= m && (x + 2) * (x + 1) / 2 + 1 <= n){
		x += 2;
	}
	ctmax(res, accumulate(a.begin(), a.begin() + x, 0LL));
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