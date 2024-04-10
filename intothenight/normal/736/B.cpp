#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	int cnt = 0;
	auto isprime = [&](int n){
		for(auto p = 2; p * p <= n; ++ p){
			if(n % p == 0){
				return false;
			}
		}
		return true;
	};
	if(isprime(n)){
		cout << "1\n";
	}
	else if(~n & 1){
		cout << "2\n";
	}
	else if(isprime(n - 2)){
		cout << "2\n";
	}
	else{
		cout << "3\n";
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