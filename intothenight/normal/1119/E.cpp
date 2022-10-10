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
	long long res = 0;
	for(auto i = 0, j = 0; i < n; ++ i){
		res += a[i] / 3, a[i] %= 3;
		while(a[i]){
			while(j <= i || j < n && a[j] <= 1){
				++ j;
			}
			if(j == n){
				break;
			}
			int x = min(a[i], a[j] / 2);
			a[i] -= x, a[j] -= 2 * x;
			res += x;
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