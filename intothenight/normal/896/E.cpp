#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,tune=native,popcnt,lzcnt,abm,bmi,bmi2")
#pragma GCC target("sse,sse2,sse3,sse4,sse4.1,sse4.2,tune=native,popcnt,lzcnt,abm,bmi,bmi2")



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	mt19937 rng(1564);
	int n, qn;
	cin >> n >> qn;
	int a[100000];
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int type, l, r, x;
		cin >> type >> l >> r >> x, -- l;
		if(type == 1){
			for(auto i = l; i < r; ++ i){
				if(a[i] > x){
					a[i] -= x;
				}
			}
		}
		else{
			int res = 0;
			for(auto i = l; i < r; ++ i){
				res += a[i] == x;
			}
			cout << res << "\n";
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