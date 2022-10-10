#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	cin >> ws;
	for(auto i = 0; i < n; ++ i){
		string s;
		getline(cin, s);
		if(count_if(s.begin(), s.end(), [&](char c){ return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'; }) != a[i]){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////