#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	string s;
	cin >> n >> qn >> s;
	const int mx = 26;
	vector<array<int, mx>> cnt(n + 1);
	for(auto i = 0; i < n; ++ i){
		cnt[i + 1] = cnt[i];
		++ cnt[i + 1][s[i] - 'a'];
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l;
		int res = 0;
		for(auto c = 0; c < mx; ++ c){
			res += (c + 1) * (cnt[r][c] - cnt[l][c]);
		}
		cout << res << "\n";
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