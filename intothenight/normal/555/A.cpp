#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	int res = 0, cnt = 0;
	for(auto rep = 0; rep < k; ++ rep){
		int m;
		cin >> m;
		vector<int> a(m);
		for(auto i = 0; i < m; ++ i){
			cin >> a[i];
		}
		int t = 0;
		if(a[0] == 1){
			t = 1;
			while(t < m && a[t - 1] + 1 == a[t]){
				++ t;
			}
			cnt += 1 + m - t;
			res += m - t;
		}
		else{
			cnt += m;
			res += m - 1;
		}
	}
	cout << res + cnt - 1 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////