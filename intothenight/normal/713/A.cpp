#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int qn;
	cin >> qn;
	map<int, int> cnt;
	for(auto qi = 0; qi < qn; ++ qi){
		char type;
		string s;
		cin >> type >> s;
		int x = 0;
		for(auto c: s){
			x <<= 1;
			if(c - '0' & 1){
				x |= 1;
			}
		}
		switch(type){
			case '+':
			++ cnt[x];
			break;
			case '-':
			-- cnt[x];
			break;
			default:
			cout << cnt[x] << "\n";
		}
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