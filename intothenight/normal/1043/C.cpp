#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = int(s.size());
	vector<int> res(n);
	for(auto i = n - 1, state = 1; i > 0; -- i){ // 1: sorted, 0: rev-sorted
		if(state ^ s[i] - 'a'){
			res[i] = 1;
			state ^= 1;
		}
	}
	for(auto x: res){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}

/*
babbbaaaaababa

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////