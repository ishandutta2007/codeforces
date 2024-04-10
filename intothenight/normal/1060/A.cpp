#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	string s;
	cin >> n >> s;
	array<int, 10> cnt{};
	for(auto c: s){
		++ cnt[c - '0'];
	}
	cout << min(cnt[8], accumulate(cnt.begin(), cnt.end(), 0) / 11) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////