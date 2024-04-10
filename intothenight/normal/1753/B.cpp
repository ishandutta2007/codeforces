#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, obj;
	cin >> n >> obj;
	map<int, int> mp;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		++ mp[x];
	}
	while(true){
		auto [x, c] = *mp.begin();
		if(c % (x + 1)){
			break;
		}
		mp[x + 1] += c / (x + 1);
		mp.erase(mp.begin());
	}
	mp.begin()->first >= obj ? cout << "Yes\n" : cout << "No\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////