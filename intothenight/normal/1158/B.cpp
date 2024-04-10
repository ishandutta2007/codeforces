#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	if(n == 1){
		cout << "1\n";
	}
	else if(k <= (n - 2) / 3 + 2){
		string s(n, '0');
		s[n - k >> 1] = '1';
		s[n - 1 - (n - k >> 1)] = '1';
		cout << s << "\n";
	}
	else{
		int p = (n - k) / 2 + 1;
		for(auto t = 0; t < n; ++ t){
			int i = n - 1 - t;
			cout << (i % p == p - 1);
		}
		cout << "\n";
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