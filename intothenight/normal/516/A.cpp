#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	string s;
	cin >> n >> s;
	string res;
	for(auto c: s){
		if(c >= '2'){
			if(c == '4'){
				res += "223";
			}
			else if(c == '6'){
				res += "35";
			}
			else if(c == '8'){
				res += "7222";
			}
			else if(c == '9'){
				res += "7233";
			}
			else{
				res += c;
			}
		}
	}
	sort(res.rbegin(), res.rend());
	cout << res << "\n";
	return 0;
}

/*
1!
2!
3!
4! = 2! * 2! * 3!
5! 
6! = 5! * 3!
7!
8! = 7! * 2! * 2! * 2!
9! = 7! * 2! * 3! * 3!
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////