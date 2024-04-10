#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	if(a.front() != a.back()){
		cout << n - 1 << "\n";
		return 0;
	}
	int p = 0, q = n - 1;
	while(a[0] == a[p]){
		++ p;
	}
	while(a[0] == a[q]){
		-- q;
	}
	cout << max(q, n - 1 - p) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////