#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for(auto i = 0; i < m; ++ i){
		string s(m, '0');
		s[i] = '1';
		cout << "? " << s << endl;
		cin >> a[i];
	}
	vector<int> order(m);
	iota(order.begin(), order.end(), 0);
	ranges::sort(order, [&](int i, int j){ return a[i] < a[j]; });
	int res = 0;
	string state(m, '0');
	for(auto i: order){
		res += a[i];
		state[i] = '1';
		cout << "? " << state << endl;
		int w;
		cin >> w;
		if(res != w){
			res -= a[i];
			state[i] = '0';
		}
	}
	cout << "! " << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////