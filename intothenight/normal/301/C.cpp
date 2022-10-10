#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto add = [&](string s, string t, bool kill = false)->void{
		cout << s << (kill ? "<>" : ">>") << t << endl;
	};
	add("???", "", true);
	add("9??", "??0");
	for(auto x = 0; x < 9; ++ x){
		add(string({x + '0'}) + "??", string({x + 1 + '0'}) + "???");
	}
	add("??", "1???");
	for(auto x = 0; x < 10; ++ x){
		add({'?', x + '0'}, {x + '0', '?'});
	}
	add("?", "??");
	add("", "?");
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////