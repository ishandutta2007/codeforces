#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	sort(a.begin(), a.end()), a.erase(unique(a.begin(), a.end()), a.end());
	for(auto i = 0; i + 3 <= n; ++ i){
		if(a[i] + 1 == a[i + 1] && a[i] + 2 == a[i + 2]){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////