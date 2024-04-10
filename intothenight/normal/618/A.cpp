#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a;
	for(auto i = 0; i < n; ++ i){
		a.push_back(1);
		while((int)a.size() >= 2 && *a.rbegin() == *next(a.rbegin())){
			int x = *a.rbegin() + 1;
			a.pop_back(), a.pop_back();
			a.push_back(x);
		}
	}
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