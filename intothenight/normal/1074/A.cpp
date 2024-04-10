#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> vert;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		vert.push_back(x);
	}
	sort(vert.begin(), vert.end());
	vert.push_back(1e9);
	vector<int> hori;
	for(auto i = 0; i < m; ++ i){
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		if(x1 == 1){
			hori.push_back(x2);
		}
	}
	sort(hori.begin(), hori.end());
	int res = m;
	for(auto i = 0, j = 0; i < int(vert.size()); ++ i){
		while(j < int(hori.size()) && hori[j] < vert[i]){
			++ j;
		}
		ctmin(res, i + int(hori.size()) - j);
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