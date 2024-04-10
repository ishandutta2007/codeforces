#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	long long res = 1LL * n * (n + 1) / 2;
	for(auto i = 0; i < n - 1; ++ i){
		if(a[i] != a[i + 1]){
			res += 1LL * (i + 1) * (n - 1 - i);
		}
	}
	for(auto i = 0; i < m; ++ i){
		int p, x;
		cin >> p >> x, -- p;
		for(auto i = max(0, p - 1); i <= min(p, n - 2); ++ i){
			if(a[i] != a[i + 1]){
				res -= 1LL * (i + 1) * (n - 1 - i);
			}
		}
		a[p] = x;
		for(auto i = max(0, p - 1); i <= min(p, n - 2); ++ i){
			if(a[i] != a[i + 1]){
				res += 1LL * (i + 1) * (n - 1 - i);
			}
		}
		cout << res << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////