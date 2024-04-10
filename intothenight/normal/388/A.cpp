#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> cnt(101);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		++ cnt[x];
	}
	for(auto res = 1; ; ++ res){
		int h = 0, i = 0;
		for(auto ch = 0; ch <= 100; ++ ch){
			for(auto x = cnt[ch]; x --; ){
				if(h > ch){
					goto NEXT;
				}
				++ i;
				if(i == res){
					i = 0;
					++ h;
				}
			}
		}
		cout << res << "\n";
		return 0;
		NEXT:;
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////