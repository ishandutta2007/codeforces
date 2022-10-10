#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s;
	cin >> s;
	int res = 0;
	for(auto c: s){
		if('0' <= c && c <= '9'){
			if(c & 1){
				++ res;
			}
		}
		else{
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
				++ res;
			}
		}
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