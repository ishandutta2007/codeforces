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
	int res = 0;
	for(auto i = 0; i < n; ++ i){
		int k, x;
		cin >> k >> x;
		if(x == 1){
			res = max(res, k + 1);
		}
		else{
			int len = __lg(x);
			if(~len & 1 && x != 1 << len){
				len += 2;
			}
			else if(len & 1){
				++ len;
			}
			res = max(res, k + (len >> 1));
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