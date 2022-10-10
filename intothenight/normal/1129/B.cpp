#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int k;
	cin >> k;
	int n = 2000;
	vector<int> a(n - 1, (n + k) / (n - 1));
	for(auto i = 0; i < (n + k) % (n - 1); ++ i){
		++ a[i];
	}
	a.insert(a.begin(), -1);
	cout << n << "\n";
	for(auto x: a){
		cout << x << " ";
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