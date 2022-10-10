#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	long long n;
	cin >> n;
	string s = to_string(n);
	-- s[0];
	for(auto i = 1; i < (int)s.size(); ++ i){
		s[i] = '9';
	}
	long long a = stoll(s), b = n - a;
	auto calc = [&](long long x){
		int res = 0;
		while(x){
			res += x % 10;
			x /= 10;
		}
		return res;
	};
	cout << calc(a) + calc(b) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////