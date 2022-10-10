#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	const int mx = 1e6;
	vector<int> f(mx + 1);
	iota(f.begin(), f.begin() + 10, 0);
	for(auto x = 10; x <= mx; ++ x){
		int p = 1;
		for(auto t = x; t; t /= 10){
			if(t % 10){
				p *= t % 10;
			}
		}
		f[x] = f[p];
	}
	vector<array<int, 10>> cnt(mx + 2);
	for(auto x = 0; x <= mx; ++ x){
		cnt[x + 1] = cnt[x];
		++ cnt[x + 1][f[x]];
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r, k;
		cin >> l >> r >> k, ++ r;
		cout << cnt[r][k] - cnt[l][k] << "\n";
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