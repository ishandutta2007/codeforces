#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	array<int, 3> n;
	for(auto i = 0; i < 3; ++ i){
		cin >> n[i];
	}
	long long tot = 0;
	array<long long, 3> s{};
	array<int, 3> minval;
	fill(minval.begin(), minval.end(), numeric_limits<int>::max());
	for(auto i = 0; i < 3; ++ i){
		for(auto j = 0; j < n[i]; ++ j){
			int x;
			cin >> x;
			ctmin(minval[i], x);
			s[i] += x;
		}
	}
	sort(minval.begin(), minval.end());
	cout << s[0] + s[1] + s[2] - min({2LL * (minval[0] + minval[1]), 2 * s[0], 2 * s[1], 2 * s[2]}) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////