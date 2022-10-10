#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> res;
	for(auto x = 2; x <= n; ++ x){
		int p = 2;
		while(x % p){
			++ p;
		}
		int y = p;
		while(y < x){
			y *= p;
		}
		if(x == y){
			res.push_back(x);
		}
	}
	cout << (int)res.size() << "\n";
	for(auto x: res){
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