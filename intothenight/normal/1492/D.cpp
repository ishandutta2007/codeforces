#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int a, b, k;
	cin >> a >> b >> k;
	if(!k){
		cout << "Yes\n" << string(b, '1') + string(a, '0') << "\n" << string(b, '1') + string(a, '0') << "\n";
		return 0;
	}

	-- b;
	string x("1"), y("1");

	if(!a || !b || k >= a + b){
		cout << "No\n";
		return 0;
	}

	x += '1', y += '0';
	-- k, -- a, -- b;
	while(k --){
		if(a){
			-- a;
			x += '0', y += '0';
		}
		else if(b){
			-- b;
			x += '1', y += '1';
		}
		else assert(false);
	}
	x += '0', y += '1';

	x += string(a, '0') + string(b, '1'), y += string(a, '0') + string(b, '1');

	cout << "Yes\n" << x << "\n" << y << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////