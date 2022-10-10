#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0], a[i][1] = i;
	}
	sort(a.rbegin(), a.rend());
	a.resize(m);
	sort(a.begin(), a.end(), [&](auto p, auto q){ return p[1] < q[1]; });
	int res = 0;
	for(auto i = 0; i < m; ++ i){
		res += a[i][0];
	}
	cout << res << "\n";
	int p = -1;
	for(auto i = 0; i < m - 1; ++ i){
		cout << a[i][1] - p << " ";
		p = a[i][1];
	}
	cout << n - 1 - p << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////