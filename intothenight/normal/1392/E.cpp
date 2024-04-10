#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < n; ++ j){
			if(!i && !j){
				cout << "0 ";
			}
			else{
				cout << (i & 1) * (1LL << i + j - 1) << " ";
			}
		}
		cout << endl;
	}
	auto ans = [&](int x, int y){
		cout << x + 1 << " " << y + 1 << endl;
	};
	int qq;
	cin >> qq;
	while(qq --){
		long long k;
		cin >> k;
		int x = 0, y = 0;
		ans(x, y);
		while(x != n - 1 || y != n - 1){
			long long mask = 1LL << x + y;
			if(k & mask){
				if(x & 1){
					++ y;
				}
				else{
					++ x;
				}
			}
			else{
				if(x & 1){
					++ x;
				}
				else{
					++ y;
				}
			}
			ans(x, y);
		}
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