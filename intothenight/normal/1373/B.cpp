#include "bits/stdc++.h"
using namespace std;



int SOLVE(){
	string s;
	cin >> s;
	array<int, 2> cnt{};
	for(auto c: s){
		++ cnt[c - '0'];
	}
	min(cnt[0], cnt[1]) & 1 ? cout << "DA\n" : cout << "NET\n";
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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