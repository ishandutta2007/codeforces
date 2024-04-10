#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	string s;
	cin >> n >> qn >> s;
	set<int> pos;
	for(auto i = 0; i + 3 <= n; ++ i){
		if(s.substr(i, 3) == "abc"){
			pos.insert(i);
		}
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int i;
		char c;
		cin >> i >> c, -- i;
		for(auto j = max(i - 2, 0); j <= i && j + 3 <= n; ++ j){
			if(s.substr(j, 3) == "abc"){
				pos.erase(j);
			}
		}
		s[i] = c;
		for(auto j = max(i - 2, 0); j <= i && j + 3 <= n; ++ j){
			if(s.substr(j, 3) == "abc"){
				pos.insert(j);
			}
		}
		cout << (int)pos.size() << "\n";
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