#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	int pos = 0;
	const int mx = 2e4;
	for(auto i = 0; i < n; ++ i){
		int x;
		string s;
		cin >> x >> s;
		if(pos == 0){
			if(s[0] != 'S'){
				cout << "NO\n";
				return 0;
			}
		}
		else if(pos == mx){
			if(s[0] != 'N'){
				cout << "NO\n";
				return 0;
			}
		}
		if(s[0] == 'N'){
			if(pos - x < 0){
				cout << "NO\n";
				return 0;
			}
			pos -= x;
		}
		else if(s[0] == 'S'){
			if(pos + x > mx){
				cout << "NO\n";
				return 0;
			}
			pos += x;
		}
	}
	pos == 0 ? cout << "YES\n" : cout << "NO\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////