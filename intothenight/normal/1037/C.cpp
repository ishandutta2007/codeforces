#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	string a, b;
	cin >> n >> a >> b;
	int res = 0;
	for(auto i = 0; i < n; ++ i){
		if(a[i] != b[i]){
			++ res;
			if(i < n - 1 && a[i + 1] != b[i + 1] && a[i] != a[i + 1]){
				++ i;
			}
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////