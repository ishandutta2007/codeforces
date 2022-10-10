#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	map<int, int, greater<>> mp;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		++ mp[x];
	}
	for(auto [x, cnt]: mp){
		if(cnt & 1){
			cout << "Conan\n";
			return 0;
		}
	}
	cout << "Agasa\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////