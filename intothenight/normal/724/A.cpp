#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	vector<string> a{"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
	string s, t;
	cin >> s >> t;
	for(auto i = 0; i < 7; ++ i){
		if(s == a[i] && t == a[i] || s == a[i] && t == a[i + 2] || s == a[i] && t == a[i + 3]){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////