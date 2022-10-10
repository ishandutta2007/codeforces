#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	adjacent_difference(a.begin(), a.end(), a.begin());
	a.erase(a.begin());
	vector<long long> prefp(n), prefn(n);
	for(auto i = 0; i < n - 1; ++ i){
		prefp[i + 1] = prefp[i];
		prefn[i + 1] = prefn[i];
		if(a[i] >= 0){
			prefp[i + 1] += a[i];
		}
		else{
			prefn[i + 1] -= a[i];
		}
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l, -- r;
		if(l < r){
			cout << prefn[r] - prefn[l] << "\n";
		}
		else{
			cout << prefp[l] - prefp[r] << "\n";
		}
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