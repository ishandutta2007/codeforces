#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	ranges::sort(a);
	if(k == 1){
		cout << n << "\n";
		return 0;
	}
	vector<int> used(n);
	int res = 0;
	for(auto i = 0; i < n; ++ i){
		if(used[i]){
			continue;
		}
		int x = a[i], cnt = 1;
		used[i] = true;
		while(true){
			if(__builtin_mul_overflow_p(x, k, 0)){
				break;
			}
			x *= k;
			if(!ranges::binary_search(a, x)){
				break;
			}
			++ cnt;
			used[ranges::lower_bound(a, x) - a.begin()] = true;
		}
		res += cnt + 1 >> 1;
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