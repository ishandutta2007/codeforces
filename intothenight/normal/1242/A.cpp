#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	long long n;
	cin >> n;
	for(auto p = 2; 1LL * p * p <= n; ++ p){
		if(n % p == 0){
			while(n % p == 0){
				n /= p;
			}
			if(n == 1){
				cout << p << "\n";
			}
			else{
				cout << "1\n";
			}
			return 0;
		}
	}
	cout << n << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////