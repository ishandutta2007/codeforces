#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<long long> s(n);
	for(auto i = 1; i < n; i += 2){
		static int prev = 0;
		int x;
		cin >> x;
		int p = -1;
		for(auto d = 1; d * d <= x; ++ d){
			if(x % d == 0 && d % 2 == x / d % 2 && prev < (x / d - d) / 2){
				p = d;
			}
		}
		if(!~p){
			cout << "No\n";
			return 0;
		}
		s[i - 1] = (x / p - p) / 2, s[i] = (x / p + p) / 2;
		prev = s[i];
	}
	cout << "Yes\n" << 1LL * s[0] * s[0] << " ";
	for(auto i = 1; i < n; ++ i){
		cout << 1LL * s[i] * s[i] - 1LL * s[i - 1] * s[i - 1] << " ";
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