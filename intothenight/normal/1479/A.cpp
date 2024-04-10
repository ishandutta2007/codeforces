#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto query = [&](int i){
		cout << "? " << i + 1 << endl;
		int x;
		cin >> x;
		return x;
	};
	auto answer = [&](int i){
		cout << "! " << i + 1 << endl;
		exit(0);
	};
	int n;
	cin >> n;
	int l = 0, r = n;
	while(r - l >= 3){
		int m = l + (r - l >> 1);
		query(m) < query(m + 1) ? r = m + 1 : l = m + 1;
	}
	for(auto i = l; i < r; ++ i){
		if((!i || query(i) < query(i - 1)) && (i == n - 1 || query(i) < query(i + 1))){
			answer(i);
		}
	}
	assert(false);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////