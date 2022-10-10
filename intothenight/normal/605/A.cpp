#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> pos(n);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x, -- x;
		pos[x] = i;
	}
	int res = 0;
	for(auto x = 0; x < n; ){
		int y = x + 1;
		while(y < n && pos[y - 1] < pos[y]){
			++ y;
		}
		ctmax(res, y - x);
		x = y;
	}
	cout << n - res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////