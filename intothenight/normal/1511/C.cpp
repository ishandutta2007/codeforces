#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	const int mx = 50;
	array<int, mx> pos;
	pos.fill(-1);
	for(auto i = 0; i < n; ++ i){
		int c;
		cin >> c, -- c;
		if(!~pos[c]){
			pos[c] = i;
		}
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int c;
		cin >> c, -- c;
		assert(~pos[c]);
		cout << pos[c] + 1 << " ";
		for(auto d = 0; d < mx; ++ d){
			if(~pos[d] && pos[d] < pos[c]){
				++ pos[d];
			}
		}
		pos[c] = 0;
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////