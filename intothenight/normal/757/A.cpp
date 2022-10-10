#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string obj = "Bulbasaur";
	vector<int> objcnt(52);
	for(auto c: obj){
		if(islower(c)){
			++ objcnt[c - 'a'];
		}
		else{
			++ objcnt[c - 'A' + 26];
		}
	}
	string s;
	cin >> s;
	vector<int> cnt(52);
	for(auto c: s){
		if(islower(c)){
			++ cnt[c - 'a'];
		}
		else{
			++ cnt[c - 'A' + 26];
		}
	}
	int res = numeric_limits<int>::max();
	for(auto c = 0; c < 52; ++ c){
		if(objcnt[c]){
			ctmin(res, cnt[c] / objcnt[c]);
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