#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	int x = *max_element(a.begin(), a.end());
	int res = 0;
	for(auto i = 0; i < n; ++ i){
		if(a[i] == x){
			int r = i;
			while(r < n && a[r] == x){
				++ r;
			}
			ctmax(res, r - i);
			i = r;
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