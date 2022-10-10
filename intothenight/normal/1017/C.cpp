#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	int sq = sqrt(n);
	vector<int> res(n);
	for(auto b = 0, x = n; b * sq < n; ++ b){
		for(auto i = min(n - 1, (b * sq + sq) - 1); i >= b * sq; -- i){
			res[i] = x --;
		}
	}
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