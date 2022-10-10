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
	vector<long long> pref(n + 1);
	ranges::sort(a);
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] = pref[i] + a[i];
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int x, y;
		cin >> x >> y;
		cout << pref[n - x + y] - pref[n - x] << "\n";
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