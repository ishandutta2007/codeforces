#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	if(n <= 3){
		cout << "NO\n";
	}
	else if(n == 4){
		cout << "YES\n1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
	}
	else if(n == 5){
		cout << "YES\n2 * 4 = 8\n3 * 5 = 15\n8 + 15 = 23\n23 + 1 = 24\n";
	}
	else{
		cout << "YES\n4 * 6 = 24\n2 + 3 = 5\n5 - 5 = 0\n0 * 1 = 0\n";
		for(auto i = 7; i <= n; ++ i){
			cout << i << " * 0 = 0\n";
		}
		cout << "24 - 0 = 24\n";
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