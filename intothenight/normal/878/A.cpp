#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	array<int, 10> state{}; // 0: don't change, 1: flip, 2: set to 0, 3: set to 1
	int n;
	cin >> n;
	for(auto i = 0; i < n; ++ i){
		char op;
		int x;
		cin >> op >> x;
		for(auto bit = 0; bit < 10; ++ bit){
			switch(op){
				case '&':
				if(~x & 1 << bit){
					state[bit] = 2;
				}
				break;
				case '|':
				if(x & 1 << bit){
					state[bit] = 3;
				}
				break;
				default:
				if(x & 1 << bit){
					state[bit] ^= 1;
				}
			}
		}
	}
	cout << "3\n";
	cout << "& ";
	int x = 1023;
	for(auto bit = 0; bit < 10; ++ bit){
		if(state[bit] == 2){
			x ^= 1 << bit;
		}
	}
	cout << x << "\n";
	cout << "| ";
	x = 0;
	for(auto bit = 0; bit < 10; ++ bit){
		if(state[bit] == 3){
			x ^= 1 << bit;
		}
	}
	cout << x << "\n";
	x = 0;
	cout << "^ ";
	for(auto bit = 0; bit < 10; ++ bit){
		if(state[bit] == 1){
			x ^= 1 << bit;
		}
	}
	cout << x << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////