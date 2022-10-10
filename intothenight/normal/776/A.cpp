#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string a, b;
	cin >> a >> b;
	cout << a << " " << b << "\n";
	int n;
	cin >> n;
	for(auto i = 0; i < n; ++ i){
		string c, d;
		cin >> c >> d;
		if(a == c){
			a = d;
		}
		else{
			b = d;
		}
		cout << a << " " << b << "\n";
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