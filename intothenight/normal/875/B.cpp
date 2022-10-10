#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> flag(n);
	cout << "1 ";
	for(auto i = 0, last = n; i < n; ++ i){
		int p;
		cin >> p, -- p;
		flag[p] = true;
		while(last && flag[last - 1]){
			-- last;
		}
		cout << (i + 2 - (n - last)) << " ";
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