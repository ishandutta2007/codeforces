#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, a, b;
	cin >> n >> a >> b;
	for(auto na = 0; na * a <= n; ++ na){
		if((n - na * a) % b == 0){
			int nb = (n - na * a) / b;
			int s = 1;
			for(auto rep = 0; rep < na; ++ rep){
				for(auto i = 0; i < a - 1; ++ i){
					cout << s + i + 1 << " ";
				}
				cout << s << " ";
				s += a;
			}
			for(auto rep = 0; rep < nb; ++ rep){
				for(auto i = 0; i < b - 1; ++ i){
					cout << s + i + 1 << " ";
				}
				cout << s << " ";
				s += b;
			}
			cout << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////